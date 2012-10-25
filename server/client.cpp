#include "client.hpp"
#include "messagehandler.hpp"

#include <Message/LoginFailure>
#include <Message/LoginSuccess>

#include <QDebug>

Client::Client(QTcpSocket* socket, QObject* parent) :
    QObject(parent), m_socket(socket), tailleMessage(0)
{
    messageHandler = new MessageHandler(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(socket, SIGNAL(disconnected()), this, SIGNAL(disconnected()));
}

Client::~Client()
{
    DataAccessor::instance().saveSlot(static_cast<sPlayer*>(DataAccessor::getPlayer(id())));
}

void Client::send(const Message::Message& message)
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    out << (quint16) 0; // On �crit 0 au d�but du paquet pour r�server la place pour �crire la taille
    message.serialize(out); // On ajoute le message � la suite
    out.device()->seek(0); // On se replace au d�but du paquet
    out << (quint16) (paquet.size() - sizeof(quint16)); // On �crase le 0 qu'on avait r�serv� par la longueur du message
    write(paquet);
}

void Client::write(const QByteArray& paquet)
{
    m_socket->write(paquet);
}

void Client::donneesRecues()
{
    Q_ASSERT(m_socket == sender());
//    qDebug() << "Client::donneesRecues()";
    QDataStream in(m_socket);
    if(tailleMessage == 0)
    {
        if (m_socket->bytesAvailable() < (int)sizeof(quint16)) return;
        in >> tailleMessage;
    }
    if (m_socket->bytesAvailable() < tailleMessage) return;

    Message::Message* message = Message::Message::extract(in);
//    qDebug() << message->id();
    messageHandler->traiter(message);
    message->deleteLater();
    tailleMessage = 0;
}

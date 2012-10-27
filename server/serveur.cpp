#include "serveur.hpp"
#include "client.hpp"
#include "sutils.hpp"
#include "localserveur.hpp"

#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QStringList>
#include <QTimer>

#include <QDebug>

Serveur::Serveur(QObject *parent) :
    QObject(parent)
{
    serveur = new QTcpServer(this);
    //connect(qApp, SIGNAL(aboutToQuit()), this, SLOT(onQuit()));

    m_localServeur = new LocalServeur(this);
}

bool Serveur::start()
{
    if (!serveur->listen(QHostAddress::Any, 50885))
    {
        /*Utils::out*/ qDebug() << "Le serveur n'a pas pu être démarré. Raison :\n" << serveur->errorString();
        return false;
    }
//    Utils::out << "serveur démarré\n" << endl;
    qDebug() << "serveur démarré";

    connect(serveur, SIGNAL(newConnection()), this, SLOT(nouvelleConnexion()));
    qDebug() << "serveur pret";
    return true;
}

QString Serveur::status() const
{
    QString res;
    /*res += "server status:\n";
    res += QString::number(clients.size()) + " clients connectés\n";*/
    res += "server status: ";
    res += QString::number(clients.size()) + " clients connectes";

    return res;
}

void Serveur::envoyerATous(const Message::Message& message)
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    out << (quint16) 0; // On écrit 0 au début du paquet pour réserver la place pour écrire la taille
    message.serialize(out); // On ajoute le message à la suite
    out.device()->seek(0); // On se replace au début du paquet
    out << (quint16) (paquet.size() - sizeof(quint16)); // On écrase le 0 qu'on avait réservé par la longueur du message
    for(int i = 0; i<clients.size(); i++)
    {
        clients.at(i)->write(paquet);
    }
}

void Serveur::nouvelleConnexion()
{
    QTcpSocket* socket = serveur->nextPendingConnection();
    Client* nouveauClient = new Client(socket, this);
    clients << nouveauClient;
    connect(nouveauClient, SIGNAL(disconnected()), this, SLOT(deconnexionClient()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onSocketError(QAbstractSocket::SocketError)));
}

void Serveur::deconnexionClient()
{
    Client* client = qobject_cast<Client*>(sender());
    Q_ASSERT(client != 0);
    clients.removeOne(client);
    client->deleteLater();
}

void Serveur::onSocketError(QAbstractSocket::SocketError err)
{
//    Utils::out << "SocketError: " << err;
    qDebug() << "SocketError: " << err;
}

/*
void Serveur::onQuit()
{
    qDebug() << "onQuit()";
    DataAccessor::instance().clearAll();
    DataAccessor::instance().processSavingQueue();
}
*/

void Serveur::shutdown()
{
    qDebug() << "shuting down";
    deleteLater();
}

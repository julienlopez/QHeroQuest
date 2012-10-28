#include "localserverconnexion.hpp"

#include <Commande/Status>
#include <Commande/StatusUpdate>
#include <Commande/Shutdown>

LocalServerConnexion::LocalServerConnexion(QObject *parent) :
    QObject(parent), tailleMessage(0)
{
    m_socket = new QLocalSocket(this);
    connect(m_socket, SIGNAL(connected()), this, SLOT(onConnexion()));
    connect(m_socket, SIGNAL(disconnected()), this, SLOT(onDeconnexion()));
    connect(m_socket, SIGNAL(error(QLocalSocket::LocalSocketError)), this, SLOT(onError(QLocalSocket::LocalSocketError)));
    connect(m_socket, SIGNAL(stateChanged(QLocalSocket::LocalSocketState)), this, SLOT(onStateChanged(QLocalSocket::LocalSocketState)));
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    m_socket->connectToServer("QHeroQuestServer");
}

void LocalServerConnexion::handle(Commande::Commande* commande)
{
    qDebug() << "commande reçue " << commande->id();
    if(commande->id() == 3)
    {
        Commande::StatusUpdate* s = qobject_cast<Commande::StatusUpdate*>(commande);
        qDebug() << s->message();
        return;
    }
    qDebug() << "commande inconnue " << commande->id();
}

void LocalServerConnexion::onConnexion()
{
    qDebug() << "connexion";
}

void LocalServerConnexion::onDeconnexion()
{
    qDebug() << "déconnexion";
}

void LocalServerConnexion::onError(QLocalSocket::LocalSocketError socketError)
{
    qDebug() << "error: " << socketError;
    if(socketError == QLocalSocket::ServerNotFoundError)
    {
        qDebug() << "impossible de se connecter au serveur";
        emit quit(); //qApp->quit();//exit();
        return;
    }
    qDebug() << m_socket->errorString();
}

void LocalServerConnexion::onStateChanged(QLocalSocket::LocalSocketState socketState)
{
    if(socketState == QLocalSocket::ConnectingState)
    {
        qDebug()  << "connexion en cours";
        return;
    }
    if(socketState == QLocalSocket::ConnectedState)
    {
        qDebug()  << "connecté";
        return;
    }

    qDebug() << "state changed: " << socketState;
}

void LocalServerConnexion::send(const Commande::Commande& commande)
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    out << (quint16) 0; // On écrit 0 au début du paquet pour réserver la place pour écrire la taille
    commande.serialize(out); // On ajoute le message à la suite
    out.device()->seek(0); // On se replace au début du paquet
    out << (quint16) (paquet.size() - sizeof(quint16)); // On écrase le 0 qu'on avait réservé par la longueur du message
    write(paquet);
}

void LocalServerConnexion::write(const QByteArray& paquet)
{
    m_socket->write(paquet);
}

void LocalServerConnexion::donneesRecues()
{
    qDebug() << "Client::donneesRecues()";
    QDataStream in(m_socket);
    if(tailleMessage == 0)
    {
        if (m_socket->bytesAvailable() < (int)sizeof(quint16)) return;
        in >> tailleMessage;
    }
    if (m_socket->bytesAvailable() < tailleMessage) return;

    Commande::Commande* commande = Commande::Commande::extract(in);
    qDebug() << commande->id();
    handle(commande);
    commande->deleteLater();
    tailleMessage = 0;
}

void LocalServerConnexion::sendShutdown()
{
    send(Commande::Shutdown());
}

void LocalServerConnexion::sendStatus()
{
    send(Commande::Status());
}

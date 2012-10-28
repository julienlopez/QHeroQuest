#ifndef LOCALSERVERCONNEXION_HPP
#define LOCALSERVERCONNEXION_HPP

#include <Commande/Commande>

#include <QObject>
#include <QLocalSocket>

class LocalServerConnexion : public QObject
{
    Q_OBJECT
public:
    explicit LocalServerConnexion(QObject *parent = 0);

private:
    quint16 tailleMessage;
    QLocalSocket* m_socket;

    void handle(Commande::Commande* commande);

signals:
    void quit();

private slots:
    void onConnexion();
    void onDeconnexion();
    void onError(QLocalSocket::LocalSocketError socketError);
    void onStateChanged(QLocalSocket::LocalSocketState socketState);
    void send(const Commande::Commande& commande);
    void write(const QByteArray& paquet);
    void donneesRecues();

public slots:
    void sendShutdown();
    void sendStatus();
    
};

#endif // LOCALSERVERCONNEXION_HPP

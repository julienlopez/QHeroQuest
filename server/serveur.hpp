#ifndef SERVEUR_HPP
#define SERVEUR_HPP

#include <Message/Message>

#include <QObject>
#include <QAbstractSocket>

class Client;
class QTcpServer;
class QTimer;
class LocalServeur;
class Position;

class Serveur : public QObject
{
    Q_OBJECT
public:
    explicit Serveur(QObject *parent = 0);

    bool start();
    QString status() const;

private:
    QList<Client*> clients;
    QTcpServer* serveur;
    LocalServeur* m_localServeur;

    void envoyerATous(const Message::Message& message);

signals:

private slots:
    void nouvelleConnexion();
    void deconnexionClient();
    void onSocketError(QAbstractSocket::SocketError);
    //void onQuit();

public slots:
    void shutdown();
};

#endif // SERVEUR_HPP

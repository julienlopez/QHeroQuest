#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <QObject>

class QTcpSocket;
class MessageHandler;

namespace Message {
    class Message;
}

class Client : public QObject
{
    Q_OBJECT
public:
    Client(QTcpSocket* socket, QObject *parent = 0);
    ~Client();

    void send(const Message::Message& message);
    void write(const QByteArray& paquet);

private:
    QTcpSocket* m_socket;
    MessageHandler* messageHandler;
    quint16 tailleMessage;

signals:
    void disconnected();

private slots:
    void donneesRecues();

};

#endif // CLIENT_HPP

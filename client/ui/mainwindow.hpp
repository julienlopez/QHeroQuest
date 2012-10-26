#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <iMessageHandler>

#include <QMainWindow>
#include <QAbstractSocket>

class QTcpSocket;

namespace UI {

class MainWindow : public QMainWindow, public iMessageHandler
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent* evt);

private:
    quint16 tailleMessage;
    QTcpSocket* socket;

private slots:
    void send(const Message::Message& message);
    void donneesRecues();
    void connecte();
    void deconnecte();
    void erreurSocket(QAbstractSocket::SocketError);
    void handleMessage(Message::Message* message);

    void chooseConnexion();

signals:
    void messageRecu(Message::Message*);
};

}

#endif // MAINWINDOW_HPP

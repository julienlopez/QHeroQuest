#include "mainwindow.hpp"
#include"connexiondialog.hpp"

#include <Message/Message>

#include <QTcpSocket>
#include <QMessageBox>
#include <QLabel>
#include <QCloseEvent>
#include <QApplication>

#include <stdexcept>

#include <QDebug>

UI::MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), tailleMessage(0)
{
    showMaximized();
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(socket, SIGNAL(connected()), this, SLOT(connecte()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(deconnecte()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erreurSocket(QAbstractSocket::SocketError)));
    connect(this, SIGNAL(messageRecu(Message::Message*)), this, SLOT(handleMessage(Message::Message*)));

    chooseConnexion();
}

UI::MainWindow::~MainWindow()
{}

void UI::MainWindow::closeEvent(QCloseEvent* evt)
{
    socket->close();
    evt->accept();
}

void UI::MainWindow::send(const Message::Message& message)
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);
    out << (quint16) 0;
    message.serialize(out);
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));
    socket->write(paquet);
}

void UI::MainWindow::donneesRecues()
{
    QDataStream in(socket);
    if (tailleMessage == 0)
    {
        if (socket->bytesAvailable() < (int)sizeof(quint16)) return;
        in >> tailleMessage;
    }
    if (socket->bytesAvailable() < tailleMessage) return;

    Message::Message* message = Message::Message::extract(in);
    emit messageRecu(message);

    tailleMessage = 0;
}

void UI::MainWindow::connecte()
{
//    centralWidget()->deleteLater();
//    setCentralWidget(lw);
}

void UI::MainWindow::deconnecte()
{
    chooseConnexion();
}

void UI::MainWindow::erreurSocket(QAbstractSocket::SocketError e)
{
    static QString erreur = "Erreur réseau";
    switch(e)
    {
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::warning(this, erreur, "le serveur n'a pas pu être trouvé.");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::warning(this, erreur, "le serveur a refusé la connexion.");
        break;
    case QAbstractSocket::RemoteHostClosedError:
        QMessageBox::warning(this, erreur, "le serveur a coupé la connexion.");
        break;
    default:
        QMessageBox::warning(this, erreur, "ERREUR : ") + socket->errorString();
    }
    chooseConnexion();
}

void UI::MainWindow::handleMessage(Message::Message* message)
{
    /*
    if(message->id() >= 5000 && m_scene != 0) m_scene->handleMessage(message);
    else if(message->id() == 2)
    {
        const Message::LoginFailure* m = qobject_cast<const Message::LoginFailure*>(message);
        Q_ASSERT(m != 0);
        QMessageBox::information(this, "Le login a échoué", "Impossible de se logger: "+m->erreur());
        centralWidget()->deleteLater();
        LoginWidget* lw = new LoginWidget;
        connect(lw, SIGNAL(sendLogin(QString,QString)), this, SLOT(sendLogin(QString, QString)));
        setCentralWidget(lw);
    }
    else if(message->id() == Message::LoginSuccess::s_id)
    {
        QMessageBox::information(this, "Le login a réussi", "Login réussi, chargement du jeu...");
        const Message::LoginSuccess* l = qobject_cast<const Message::LoginSuccess*>(message);
        Q_ASSERT(l);
        setUpScreen(l->idPlayer());
    }
    else if(message->id() >= 1000 && message->id() < 3000)
    {
        qDebug() << "id: " << message->id() << " => " <<message;
        const Message::Erreur::ErreurServeur* e = qobject_cast<const Message::Erreur::ErreurServeur*>(message);
        Q_ASSERT(e != 0);
        QMessageBox::critical(this, "Erreur serveur", e->message());
        throw std::logic_error("Erreur critique");
    }
    else*/ QMessageBox::warning(this, "Message inconnu reçu", "Un message Inconnu a été reçu: id = " + QString::number(message->id()));
    message->deleteLater();
}

void UI::MainWindow::chooseConnexion() {
    std::pair<QHostAddress, bool> p = ConnexionDialog::promptConnexion(this);
    QHostAddress adr = p.first;
    qDebug() << adr;
    if(adr.isNull()) return;
    socket->connectToHost(adr, 50885);
    if(p.second) {

    }
}

#include "messagehandler.hpp"
#include "client.hpp"

#include <Message/Message>
#include <QDebug>

MessageHandler::MessageHandler(Client* parent) :
    QObject(parent), m_client(parent)
{}

void MessageHandler::traiter(const Message::Message* message) const
{
//    if(message->id() == 1)
//    {
//        const Message::Login* m = qobject_cast<const Message::Login*>(message);
//        Q_ASSERT(m != 0);
//        m_client->login(m->login(), m->mdp());
//    }
//    else
    qDebug() << "Données reçues : " << message->id();
}

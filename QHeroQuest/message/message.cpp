#include "message.hpp"

Message::Message::Message(quint64 id, QObject *parent) :
    QObject(parent), m_id(id)
{}

Message::Message::Message(const Message& m): QObject(m.parent()), m_id(m.m_id)
{}

quint64 Message::Message::id() const
{
    return m_id;
}

Message::Message* Message::Message::extract(QDataStream& in)
{
    quint64 id;
    in >> id;
    return type_factory::instance().create(id, in);
}

QDataStream& Message::Message::serialize(QDataStream& out) const
{
    out << m_id;
    return out;
}

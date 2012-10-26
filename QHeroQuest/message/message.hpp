#ifndef MESSAGE_H
#define MESSAGE_H

#include <Utils/Factory>

#include <QObject>
#include <QVariant>
#include <QDataStream>

namespace Message {

class Message : public QObject
{
    Q_OBJECT
public:
    typedef Utils::Factory<Message, quint64, Message*(*)(QDataStream&)> type_factory;

    Message(quint64 id =0, QObject *parent = 0);
    Message(const Message& m);

    quint64 id() const;

    static Message* extract(QDataStream& in);
    virtual QDataStream& serialize(QDataStream& out) const;

protected:
    quint64 m_id;

signals:

public slots:

};

}

#endif // MESSAGE_H

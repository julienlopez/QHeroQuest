#ifndef JSON_H
#define JSON_H

#include <QString>
#include <QVariant>

class JSon
{
public:
    JSon();

    static QString toJson(const QVariant& variant);
    static QString toJson(const QVariantMap& map);
    static QString toJson(const QVariantList& list);
    static QString toJson(qlonglong l);
    static QString toJson(const QString& str);
    static QString toJson(int i);
};

#endif // JSON_H

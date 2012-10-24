#include "json.hpp"

JSon::JSon()
{

}

QString JSon::toJson(const QVariant& variant)
{
    QVariant::Type type = variant.type();
    switch(type)
    {
        case QVariant::String:
            return toJson(variant.toString());
            break;
        case QVariant::LongLong:
            return toJson(variant.toLongLong());
            break;
        case QVariant::Map:
            return toJson(variant.toMap());
            break;
        case QVariant::List:
            return toJson(variant.toList());
            break;
        case QVariant::Int:
            return toJson(variant.toInt());
            break;
        default:
            return "format non pris en compte: " + QString(QVariant::typeToName(type));
    }
}

QString JSon::toJson(const QVariantMap& map)
{
    QString res = "{\n";
    for(QVariantMap::ConstIterator i = map.begin(); i != map.end(); ++i)
        res += '\t' + i.key() + ": " + toJson(i.value()) + " , \n";
    if(res.size() > 3) res.chop(3);
    return res + "\n}\n";
}

QString JSon::toJson(const QVariantList& list)
{
    QString res = "[\n";
    for(QVariantList::ConstIterator i = list.begin(); i != list.end(); ++i)
        res += '\t' + toJson(*i) + " , ";
    if(res.size() > 3) res.chop(3);
    return res + "\n]\n";
}

QString JSon::toJson(qlonglong l)
{
    return QString::number(l);
}

QString JSon::toJson(const QString& str)
{
    return '"'+str+'"';
}

QString JSon::toJson(int i)
{
    return QString::number(i);
}

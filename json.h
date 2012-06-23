#ifndef JSON_H
#define JSON_H


/*
  http://www.prashanthudupa.com/2011/12/20/simple-json-parser-serializer-in-qt/
 */

struct JSONData;
class JSON
{
public:
    static JSON& instance();
    ~JSON();

    QVariantMap parse(const QString& string) const;
    QString serialize(const QVariant& value) const;

protected:
    JSON();

private:
    JSONData* d;
};

static QScriptValue CreateValue(const QVariant& value, QScriptEngine& engine);

#endif // JSON_H

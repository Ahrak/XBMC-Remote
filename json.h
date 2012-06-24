#ifndef JSON_H
#define JSON_H

/**
 *
 */
struct JSONData;

/**
 * Simple Way to handle JSON Messages with QT without external library.
 * This class serializes and deserializes json messages using QVariant and QVariantMap.
 *
 * From: http://www.prashanthudupa.com/2011/12/20/simple-json-parser-serializer-in-qt/
 */
class JSON
{
public:

    /**
     * get singelton instance
     */
    static JSON& instance();

    /**
     * destructor
     */
    ~JSON();

    /**
     * parse json string and creates the QVariantMap
     * @param QString string the json string
     * @return QVariantMap json object tree
     */
    QVariantMap parse(const QString& string) const;

    /**
     * serializes object tree inside QVariant to json string
     * @param QVariant value object value
     * @return QString json string
     */
    QString serialize(const QVariant& value) const;

protected:

    /**
     * protected constructor --> singelton pattern
     */
    JSON();

private:

    /**
     * json container  object
     */
    JSONData* d;
};

/**
 *
 */
QScriptValue CreateValue(const QVariant& value, QScriptEngine& engine);

#endif // JSON_H

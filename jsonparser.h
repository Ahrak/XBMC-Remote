#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QString>
#include <QVariant>
#include <QVariantMap>
#include <QStringList>

/**
 * container for XBMC JSON Messages
 * @author tommy hartmann <toha@zlug.org>
 */
struct XBMCMessage
{

    XBMCMessage()
    {
        version = "UNKNOWN";
        method = "UNKNOWN";
        ID = 0;
        isError = false;
    }

    /** api version */
    QString version;

    /** method /command string */
    QString method;

    /** communication ID */
    int ID;

    /** flag if message is an error message */
    bool isError;

    /** result part of message */
    QVariantMap result;

    /**
     * generates a string of the message object
     * @return QString object string
     */
    QString toString() const
    {
        if(isError)
        {
            return QString("ERROR (%1)").arg(result.value("message").toString());
        }
        else
        {
            QStringList list;
            QMapIterator<QString, QVariant> i(result);
            while (i.hasNext()) {

               i.next();
               QString s = QString("%1: %2").arg(i.key()).arg(i.value().toString());
               list.append(s);
               //
            }
            return QString("OK (%1)").arg(list.join(","));
        }
    }
};


/**
 * Class that handles serializing and deserializing of
 * XBMC messages.
 */
class QJsonParser
{
public:

    /**
     * Constructor
     */
    QJsonParser();

    /**
     * parse XBMC message from response string
     * @param QString result response string
     */
    XBMCMessage parseFromRequest(const QString& result) const;
};

#endif // JSONPARSER_H

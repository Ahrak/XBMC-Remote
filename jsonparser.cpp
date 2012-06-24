#include "includes.h"

QJsonParser::QJsonParser()
{
}

XBMCMessage QJsonParser::parseFromRequest(const QString &result) const
{
    QVariantMap jsonObject = JSON::instance().parse(result);
    XBMCMessage xbmcMsg;

    /* DEBUG
    QMapIterator<QString, QVariant> i(jsonObject);
    while (i.hasNext()) {
       i.next();
       qDebug() << i.key() << ": " << i.value() << endl;
    }
    */

    //ERROR
    QVariant error = jsonObject.value("error");
    if (error.isValid() )
    {
        xbmcMsg.isError = true;
        QVariantMap data = error.toMap();
        xbmcMsg.result.insert("message", data.value("message"));
        return xbmcMsg;
    }

    //RESPONSE
    QVariant vResult = jsonObject.value("result");
    if (vResult.isValid())
    {
        if(vResult.type() == QVariant::Map)
        {
         //
         QVariantMap data = vResult.toMap();
         for(QVariantMap::Iterator it = data.begin(); it != data.end(); it++)
         {
             xbmcMsg.result.insert(it.key(), it.value());
         }
        }
        else if(vResult.type() == QVariant::String)
        {
            xbmcMsg.result.insert("message", vResult.toString());
        }
    }
    return xbmcMsg;

}

#include "includes.h"

QJsonParser::QJsonParser()
{
}

XBMCMessage QJsonParser::parseFromRequest(const QString &result) const
{
    QVariantMap jsonObject = JSON::instance().parse(result);
    XBMCMessage jsonResponse;


    QMapIterator<QString, QVariant> i(jsonObject);
    while (i.hasNext()) {
       i.next();
       qDebug() << i.key() << ": " << i.value() << endl;
    }

    //ERROR
    QVariant error = jsonObject.value("error");
    if (error.isValid() )
    {
        jsonResponse.isError = true;
        QVariantMap data = error.toMap();
        jsonResponse.result.insert("message", data.value("message"));
        return jsonResponse;
    }

    /*
    //RESPONSE
    QScriptValue vResult = sc.property("result");
    if (vResult.isArray())
    {
       QStringList items;
       qScriptValueToSequence(vResult, items);
       foreach (QString str, items) {
           jsonResponse.result.insert(str, str);
       }
    }
    else if(vResult.isString())
    {
           jsonResponse.result.insert("result", vResult.toString());
    }
    */
    return jsonResponse;

}

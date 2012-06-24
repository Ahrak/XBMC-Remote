#include "includes.h"

XBMCInterface &XBMCInterface::instance()
{
    static XBMCInterface theInstance;
    return theInstance;
}

XBMCInterface::XBMCInterface()
{
}

void XBMCInterface::send(QNetworkAccessManager* qnam, QVariant message)
{
    Config config = XBMCRemoteConfig::instance().config();
    QString url = QString("http://%1:%2/jsonrpc?UpdateState").arg(config.host).arg(config.port);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QByteArray postData;
    QVariantMap foo;
    foo.insert("jsonrpc", QVariant("2.0"));
    foo.insert("id", QVariant("1"));
    foo.insert("method", message);

    QString serializedMessage = JSON::instance().serialize(foo);
    postData.append(serializedMessage);


    //
    qnam->post(request, postData);

}

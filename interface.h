#ifndef INTERFACE_H
#define INTERFACE_H

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QVariant>

class XBMCInterface
{
public:

    static XBMCInterface& instance();

    void send( QNetworkAccessManager* qnam, QVariant message);

protected:

    XBMCInterface();
};

#endif // INTERFACE_H

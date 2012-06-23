#ifndef REMOTEBUTTON_H
#define REMOTEBUTTON_H

#include "includes.h"

class RemoteButton
{
public:

    RemoteButton(QString name, int kkey, QString command, QPushButton* btn);

    QString name();

    int key();

    QString command();

    QPushButton* button();

private:

    QString m_name;

    int m_kkey;

    QString m_command;

    QPushButton* m_button;

};

#endif // REMOTEBUTTON_H

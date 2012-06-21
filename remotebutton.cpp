#include "remotebutton.h"

RemoteButton::RemoteButton(QString name, int kkey,
                           QString command, QPushButton* btn)
    : m_name(name)
    , m_kkey(kkey)
    , m_command(command)
    , m_button(btn)
{
    //
}

QString RemoteButton::name()
{
    return m_name;
}

int RemoteButton::key()
{
    return m_kkey;
}

QString RemoteButton::command()
{
    return m_command;
}

QPushButton *RemoteButton::button()
{
    return m_button;
}

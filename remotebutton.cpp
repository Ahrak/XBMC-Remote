#include "includes.h"

RemoteButton::RemoteButton(QString name, int kkey,
                           QString command, QPushButton* btn)
    : m_name(name)
    , m_kkey(kkey)
    , m_command(command)
    , m_button(btn)
{
    //
}

QString RemoteButton::name() const
{
    return m_name;
}

int RemoteButton::key() const
{
    return m_kkey;
}

QString RemoteButton::command() const
{
    return m_command;
}

QPushButton *RemoteButton::button() const
{
    return m_button;
}

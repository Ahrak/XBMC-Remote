#ifndef REMOTEBUTTON_H
#define REMOTEBUTTON_H

#include <QString>
#include <QPushButton>

/**
 * Class that represents a button of the virtual remote
 * @author tommy hartmann <toha@zlug.org>
 */
class RemoteButton
{
public:

    /**
     * constructor
     * @param QString name button name
     * @param int kkey QT keyboard code
     * @param QString command sending command string //TODO change to own type
     * @param QPushButton* btn pointer to gui button
     */
    RemoteButton(QString name, int kkey, QString command, QPushButton* btn);

    /**
     * getter for button name
     * @return QString button name
     */
    QString name() const;

    /**
     * getter for key code
     * @return int key code
     */
    int key() const;

    /**
     * getter for command string
     * @return QString command string
     */
    QString command() const;

    /**
     * getter for gui button
     * @return QPushButton* pointer to gui button object
     */
    QPushButton* button() const;

private:

    /** button name */
    QString m_name;

    /** button keyboard code */
    int m_kkey;

    /** button execution command */
    QString m_command;

    /** button ui object pointer */
    QPushButton* m_button;

};

#endif // REMOTEBUTTON_H

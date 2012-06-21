#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkReply>
#include <QDebug>
#include <QtNetwork>
#include <QKeyEvent>
#include <QPalette>

#include "remotebutton.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *);
private:
    Ui::MainWindow *ui;
    QNetworkAccessManager* qnam;
    QSignalMapper *signalMapper;

    QString method;

    QMap<QString, RemoteButton*> KEY_MAP;

    void initButtons();

private slots:
    void httpFinished(QNetworkReply*);
    void doSend();
    void sendKey(QString key);

signals:
    void clicked(const QString &text);
};

#endif // MAINWINDOW_H

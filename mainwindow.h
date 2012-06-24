#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QtNetwork>
#include <QMap>

#include <qjsonparser.h>

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

    QJsonParser jsonParser;

    void initButtons();

private slots:
    void httpFinished(QNetworkReply*);
    void doSend();
    void sendKey(QString key);

signals:
    void clicked(const QString &text);
};

#endif // MAINWINDOW_H

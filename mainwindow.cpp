#include "includes.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    signalMapper(0),
    method("")
{
    qnam = new QNetworkAccessManager();
    ui->setupUi(this);
    //
    initButtons();

    this->setFocusPolicy(Qt::NoFocus);
    ui->groupBox->setFocusPolicy(Qt::NoFocus);
    this->setFocus();

    //SIGNALS
    connect(qnam,SIGNAL(finished(QNetworkReply*)),
            this,SLOT(httpFinished(QNetworkReply*)));

    //
    signalMapper = new QSignalMapper(this);

    //
    for(QMap<QString, RemoteButton*>::Iterator it = KEY_MAP.begin(); it != KEY_MAP.end(); it++)
    {
        QPushButton* btn = it.value()->button();
        signalMapper->setMapping(btn, it.key());
        connect(btn, SIGNAL(clicked()), signalMapper, SLOT(map()));
        btn->setFocusPolicy(Qt::NoFocus);
    }
    //
    connect(signalMapper, SIGNAL(mapped(const QString &)),
                this, SIGNAL(clicked(const QString &)));
    connect(this, SIGNAL(clicked(const QString &)), this, SLOT(sendKey(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    for(QMap<QString, RemoteButton*>::Iterator it = KEY_MAP.begin(); it != KEY_MAP.end(); it++)
    {
        if(it.value()->key() == event->key())
        {
            QPushButton* btn = it.value()->button();
            //
            //emit btn->click();
            btn->animateClick(100);
            //
            //sendKey(it.key());
        }
    }
}

void MainWindow::initButtons()
{
    KEY_MAP.insert("OK",  new RemoteButton( "Ok", Qt::Key_Return, "Input.Select", ui->btnOK));
    KEY_MAP.insert("LEFT", new RemoteButton( "Left", Qt::Key_Left, "Input.Left", ui->btnLeft));
    KEY_MAP.insert("RIGHT", new RemoteButton( "Right", Qt::Key_Right, "Input.Right", ui->btnRight));
    KEY_MAP.insert("UP", new RemoteButton( "Up", Qt::Key_Up, "Input.Up", ui->btnUp));
    KEY_MAP.insert("DOWN", new RemoteButton( "Right", Qt::Key_Down, "Input.Down", ui->btnDown));
    KEY_MAP.insert("HOME", new RemoteButton( "Home", Qt::Key_Home, "Input.Home", ui->btnHome));
    KEY_MAP.insert("BACK", new RemoteButton( "Back", Qt::Key_Backspace, "Input.Back", ui->btnBack));
    //
    KEY_MAP.insert("PLAY_REV", new RemoteButton( "Rewind", Qt::Key_0, "Player.GoPrevious", ui->btnRew));
    KEY_MAP.insert("PLAY_FWD", new RemoteButton( "Forward", Qt::Key_1, "Player.GoNext", ui->btnFwd));
    KEY_MAP.insert("PLAY_PAUSE", new RemoteButton( "Pause", Qt::Key_Space, "Player.PlayPause", ui->btnPlay));
    KEY_MAP.insert("PLAY_STOP", new RemoteButton( "Stop", Qt::Key_C, "Player.Stop", ui->btnStop));
    //
    KEY_MAP.insert("VOL_UP", new RemoteButton( "Volume Up", Qt::Key_PageUp, "Application.SetVolume", ui->btnVolUp));
    KEY_MAP.insert("VOL_DOWN", new RemoteButton( "Volume Down", Qt::Key_PageDown, "Application.SetVolume", ui->btnVolDown));
}

void MainWindow::httpFinished(QNetworkReply* reply)
{
    if(reply)
    {
         QString header = reply->readAll();
         //ui->log->append("RECEIVED:" + header + "\n");
         XBMCMessage jsonResp = jsonParser.parseFromRequest(header);
         ui->log->append("RECEIVED:" + jsonResp.toString() + "\n");
    }

}

void MainWindow::doSend()
{


    QUrl url("http://192.168.1.173:8080/jsonrpc?UpdateState");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QByteArray postData;
    postData.append("{\"jsonrpc\": \"2.0\", \"method\": \""+method+"\", \"id\": 1}");
    qnam->post(request, postData);
    this->setFocus();

}

void MainWindow::sendKey(QString key)
{
    ui->log->append("KEY:" + key);
    method = KEY_MAP.find(key).value()->command();
    doSend();
}


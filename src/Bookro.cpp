#include "Bookro.h"
#include "ui_Bookro.h"


Bookro::Bookro(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Bookro)
{
    ui->setupUi(this);
    this->hide();
    this->setWindowState(Qt::WindowMinimized);

    Listener = new EvDevKeyboardListener();
    ScriptEngine = new ScriptEngineLite();

    connect(Listener, &EvDevKeyboardListener::evdevKey, this, &Bookro::keyboardListener);



    _evtest = new BookroEvTest;

    ui->comboBox->addItems(_evtest->getAllDevices());

    QSettings settings("JohnCiubuc", "Bookro");
    _evtest->setIndex(settings.value("LastEvTestIndex", 0).toInt());
    ui->comboBox->setCurrentIndex(settings.value("LastEvTestIndex", 0).toInt());

    Listener->updateEvDevice(_evtest->getTopDevice());
    Listener->startMonitor();

    createTrayIcon();
    _applicationReady = true;
}

Bookro::~Bookro()
{
    delete ui;
}

void Bookro::keyboardListener(int key, int keyState)
{
    QString keyName = ScriptEngine->getDikName(key);
    db keyName <<   ", " << keyState;
    if (keyName == "DIK_APOSTROPHE")
        _triggerKeyStatus = keyState;

    if (keyName != "DIK_APOSTROPHE" && _triggerKeyStatus == 1 && keyState == 1)
    {
        triggerMacro(keyName);
    }
}

void Bookro::triggerMacro(QString keyName)
{
    // Did we change evdev listener?
    if(_evdevTextChanged)
    {
        _evdevTextChanged = false;
        on_lineEdit_3_returnPressed();
    }
    _lastMacroKeyName = keyName;
    // Are we activating a macro?
    if (macros.contains(keyName))
    {
        ui->lineEdit->setText("'"+keyName);
        ui->lineEdit_2->setText(macros.value(keyName));
        ScriptEngine->key_backspace(2);
        ScriptEngine->key_send(macros.value(keyName));
    }
    // Are we triggering a macro but we don't have anything saved?
    else
    {
        showBookro();

        ui->lineEdit->setText("'"+keyName);
        ui->lineEdit_2->setText(QApplication::clipboard()->text(QClipboard::Selection));
    }
}


void Bookro::on_pushButton_clicked()
{
    macros[_lastMacroKeyName] = ui->lineEdit_2->text();
    ui->lineEdit_2->clear();
    this->setWindowState(Qt::WindowMinimized);
}


void Bookro::on_lineEdit_3_returnPressed()
{

}


void Bookro::on_lineEdit_3_textChanged(const QString &arg1)
{
    _evdevTextChanged = true;
}

void Bookro::createTrayIcon()
{

    _tray = new BookroSystemTrayIcon(this);
    _tray->setIcon(QIcon(":/icons/media/book-bookmark-icon.png"));
    _tray->setContextMenu(new QMenu(this));

    connect(_tray->contextMenu()->addAction("Show"), &QAction::triggered, this, [=]()
    {
        showBookro();
    });
    connect(_tray->contextMenu()->addAction("Quit"), &QAction::triggered, this, &QApplication::quit);

    _tray->show();
}

void Bookro::showBookro()
{
    this->show();
    QMainWindow::activateWindow();
    this->setFocus();
}


void Bookro::on_comboBox_currentIndexChanged(int index)
{
    if(!_applicationReady) return;
    _evtest->setIndex(index);
    Listener->updateEvDevice(_evtest->getTopDevice());
    QSettings settings("JohnCiubuc", "Bookro");
    settings.setValue("LastEvTestIndex", index);
}


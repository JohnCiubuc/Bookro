#ifndef EVDEVKEYBOARDLISTENER_H
#define EVDEVKEYBOARDLISTENER_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <stdio.h>
#include <fcntl.h>
#include <libevdev-1.0/libevdev/libevdev.h>

class EvDevKeyboardListener : public QObject
{
    Q_OBJECT
public:
    explicit EvDevKeyboardListener(QObject *parent = nullptr);

signals:
    void evdevKey(int, int);
public slots:
    void updateEvDevice(QString dev);
    void startMonitor(bool status = true);
private slots:
    void evdevTimeout();
private:
    QTimer * _evdevTimer;
    struct libevdev *_dev;
};

#endif // EVDEVKEYBOARDLISTENER_H

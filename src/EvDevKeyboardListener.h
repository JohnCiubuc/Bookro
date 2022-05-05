#ifndef EVDEVKEYBOARDLISTENER_H
#define EVDEVKEYBOARDLISTENER_H

#include <QObject>
#include <QDebug>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <libevdev-1.0/libevdev/libevdev.h>

class EvDevKeyboardListener : public QObject
{
    Q_OBJECT
public:
    explicit EvDevKeyboardListener(QObject *parent = nullptr);

signals:

};

#endif // EVDEVKEYBOARDLISTENER_H

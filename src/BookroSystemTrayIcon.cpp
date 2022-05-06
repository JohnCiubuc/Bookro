#include "BookroSystemTrayIcon.h"

BookroSystemTrayIcon::BookroSystemTrayIcon(QObject *parent)
    : QSystemTrayIcon{parent}
{
    this->installEventFilter(this);
}

bool BookroSystemTrayIcon::eventFilter(QObject *watched, QEvent *event)
{
//    qDebug() << this << event->type();
    return true;
}

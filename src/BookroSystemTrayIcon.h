#ifndef BOOKROSYSTEMTRAYICON_H
#define BOOKROSYSTEMTRAYICON_H

#include <QSystemTrayIcon>
#include <QObject>
#include <QEvent>
#include <QDebug>
class BookroSystemTrayIcon : public QSystemTrayIcon
{
    Q_OBJECT
public:
    explicit BookroSystemTrayIcon(QObject *parent = nullptr);
protected:
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // BOOKROSYSTEMTRAYICON_H

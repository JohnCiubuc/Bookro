#ifndef BOOKRO_H
#define BOOKRO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Bookro; }
QT_END_NAMESPACE

class Bookro : public QMainWindow
{
    Q_OBJECT

public:
    Bookro(QWidget *parent = nullptr);
    ~Bookro();

private:
    Ui::Bookro *ui;
};
#endif // BOOKRO_H

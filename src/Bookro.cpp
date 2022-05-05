#include "Bookro.h"
#include "src/ui_bookro.h"

Bookro::Bookro(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Bookro)
{
    ui->setupUi(this);
}

Bookro::~Bookro()
{
    delete ui;
}


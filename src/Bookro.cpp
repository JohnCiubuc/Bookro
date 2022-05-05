#include "Bookro.h"
#include "ui_Bookro.h"

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


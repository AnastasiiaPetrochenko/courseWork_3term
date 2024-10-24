#include "window4.h"
#include "ui_window4.h"

Window4::Window4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Window4)
{
    ui->setupUi(this);
}

Window4::~Window4()
{
    delete ui;
}

void Window4::on_pushButton_clicked()
{
    this->close();
}


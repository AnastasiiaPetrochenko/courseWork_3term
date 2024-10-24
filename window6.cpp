#include "window6.h"
#include "ui_window6.h"

Window6::Window6(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Window6)
{
    ui->setupUi(this);
}

Window6::~Window6()
{
    delete ui;
}

void Window6::on_pushButton_clicked()
{

}


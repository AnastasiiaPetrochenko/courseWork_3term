#include "window3.h"
#include "ui_window3.h"
#include "messageManager.h"

Window3::Window3(MessageManager* msgManager, QWidget *parent)
    : QDialog(parent), ui(new Ui::Window3), msgManager(msgManager)
{
    ui->setupUi(this);
}


Window3::~Window3()
{
    delete ui;
}

void Window3::on_pushButton_clicked() {
    QString childName = ui->lineEdit->text();
    if (!childName.isEmpty()) {
        msgManager->removeMessage(childName);  // Видаляємо повідомлення через об'єкт

        emit childRemoved(childName);  // Викликаємо сигнал видалення
    }
}


void Window3::on_pushButton_2_clicked()
{
    this->close();
}


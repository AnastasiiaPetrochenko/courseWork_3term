#include "window3.h"
#include "ui_window3.h"
#include "messageManager.h"
#include <QMessageBox>
#include <exception>

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

    try {
        if (childName.isEmpty()) {
            throw std::runtime_error("Please enter a child's name.");
        }

        msgManager->removeMessage(childName);  // Видаляємо повідомлення через об'єкт
        emit childRemoved(childName);  // Викликаємо сигнал видалення
    } catch (const std::exception& e) {
        // Обробка винятку, якщо ім'я не введено або повідомлення не знайдено
        QMessageBox::warning(this, "Error", e.what());
    }
}

void Window3::on_pushButton_2_clicked()
{
    this->close();
}

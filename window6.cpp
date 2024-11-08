#include "window6.h"
#include "ui_window6.h"


Window6::Window6(MessageManager* manager, QWidget *parent)
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
    // Очищаємо таблицю перед виводом нових даних
    ui->youngestChildrenTable->setRowCount(0);

    // Отримуємо наймолодших дітей за допомогою MessageManager
    QVector<Child*> youngestChildren = messageManager->findYoungestChildrenFromTable(
        parent()->findChild<QTableWidget*>("childrenTable")
        );

    // Додаємо дані у таблицю youngestChildrenTable
    for (int i = 0; i < youngestChildren.size(); ++i) {
        Child* child = youngestChildren[i];
        ui->youngestChildrenTable->insertRow(i);

        ui->youngestChildrenTable->setItem(i, 0, new QTableWidgetItem(child->getName()));
        ui->youngestChildrenTable->setItem(i, 1, new QTableWidgetItem(QString::number(child->getAge())));
        ui->youngestChildrenTable->setItem(i, 2, new QTableWidgetItem(child->getSpecificGift()));
    }

    // Очищуємо вектор для уникнення витоків пам'яті
    qDeleteAll(youngestChildren);
}


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

void Window6::on_pushButton_clicked(const QVector<Child*>& youngestChildren)
{
    ui->youngestChildrenTable->setRowCount(0); // Очищаємо таблицю

    for (const Child* child : children) {
        int row = ui->youngestChildrenTable->rowCount();
        ui->youngestChildrenTable->insertRow(row);

        ui->youngestChildrenTable->setItem(row, 0, new QTableWidgetItem(child->getName()));
        ui->youngestChildrenTable->setItem(row, 1, new QTableWidgetItem(QString::number(child->getAge())));
        ui->youngestChildrenTable->setItem(row, 2, new QTableWidgetItem(child->getGender() == Child::Gender::Male ? "Хлопець" : "Дівчина"));
        ui->youngestChildrenTable->setItem(row, 3, new QTableWidgetItem(QString::number(child->getGoodDeeds())));
        ui->youngestChildrenTable->setItem(row, 4, new QTableWidgetItem(QString::number(child->getBadDeeds())));
        ui->youngestChildrenTable->setItem(row, 5, new QTableWidgetItem(child->getGiftType() == Child::GiftType::Edible ? "Їстівний" : "Неїстівний"));
        ui->youngestChildrenTable->setItem(row, 6, new QTableWidgetItem(child->getSpecificGift()));
    }
}


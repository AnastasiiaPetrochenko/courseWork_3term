#include "window5.h"
#include "ui_window5.h"

Window5::Window5(MessageManager *manager, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Window5)
    , messageManager(manager) // Ініціалізуйте messageManager
{
    ui->setupUi(this);
}

Window5::~Window5() {
    delete ui;
}

void Window5::on_pushButton_2_clicked() {
    int candyCount = messageManager->countCandy();
    int chocolateCount = messageManager->countChocolate();
    int cookieCount = messageManager->countCookie();
    int carCount = messageManager->countCar();
    int dollCount = messageManager->countDoll();
    int edibleCount = messageManager->countEdibleGifts();
    int nonEdibleCount = messageManager->countNonEdibleGifts();

    // Очищаємо таблицю для результатів
    ui->tableWidget->setRowCount(7); // Додаємо два рядки для їстівних і неїстівних подарунків

    // Додаємо кількість їстівних подарунків
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("Їстівні подарунки"));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString::number(edibleCount)));

    // Додаємо кількість неїстівних подарунків
    ui->tableWidget->setItem(1, 0, new QTableWidgetItem("Неїстівні подарунки"));
    ui->tableWidget->setItem(1, 1, new QTableWidgetItem(QString::number(nonEdibleCount)));

    // Додаємо кількість цукерок
    ui->tableWidget->setItem(2, 0, new QTableWidgetItem("Цукерки"));
    ui->tableWidget->setItem(2, 1, new QTableWidgetItem(QString::number(candyCount)));

    // Додаємо кількість шоколаду
    ui->tableWidget->setItem(3, 0, new QTableWidgetItem("Шоколад"));
    ui->tableWidget->setItem(3, 1, new QTableWidgetItem(QString::number(chocolateCount)));

    // Додаємо кількість печива
    ui->tableWidget->setItem(4, 0, new QTableWidgetItem("Печиво"));
    ui->tableWidget->setItem(4, 1, new QTableWidgetItem(QString::number(cookieCount)));

    // Додаємо кількість машинок
    ui->tableWidget->setItem(5, 0, new QTableWidgetItem("Машинки"));
    ui->tableWidget->setItem(5, 1, new QTableWidgetItem(QString::number(carCount)));

    // Додаємо кількість ляльок
    ui->tableWidget->setItem(6, 0, new QTableWidgetItem("Ляльки"));
    ui->tableWidget->setItem(6, 1, new QTableWidgetItem(QString::number(dollCount)));
}


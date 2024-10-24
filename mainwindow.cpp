#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "messageManager.h"
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include "window2.h"
#include "window3.h"
#include "window4.h"
#include "window5.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , window2(nullptr)
    , window3(nullptr)
    , window4(nullptr)
    , window5(nullptr)
{
    ui->setupUi(this);

    window2 = new Window2(this);

    connect(window2, &Window2::childAdded, this, &MainWindow::addChildToTable);
    connect(window3, &Window3::childRemoved, this, &MainWindow::onChildRemoved);

    loadChildrenFromFile();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete window2;
    delete window3;
    delete window4;
    delete window5;
}


void MainWindow::loadChildrenFromFile()
{
    messageManager.clearMessages();  // Очищаємо список повідомлень перед завантаженням даних

    QFile file("C:/Users/Admin/Desktop/CourseWok/children.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);
    ui->childrenTable->setRowCount(0);  // Очищаємо таблицю перед завантаженням даних

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList childData = line.split(" ");

        if (childData.size() < 7) {
            continue;
        }

        // Витягуємо дані для дитини
        QString name = childData[0];
        int age = childData[1].toInt();
        QString genderStr = childData[2];
        int goodDeeds = childData[3].toInt();
        int badDeeds = childData[4].toInt();
        QString giftTypeStr = childData[5];
        QString specificGift = childData[6];

        Child::Gender gender = (genderStr == "Хлопець") ? Child::Gender::Male : Child::Gender::Female;
        Child::GiftType giftType = (giftTypeStr == "Їстівний") ? Child::GiftType::Edible : Child::GiftType::NonEdible;

        Child* child = new Child(name, age, gender, goodDeeds, badDeeds, giftType, specificGift);
        messageManager.addMessage(child);  // Додаємо в MessageManager

        int rowCount = ui->childrenTable->rowCount();
        ui->childrenTable->insertRow(rowCount);

        ui->childrenTable->setItem(rowCount, 0, new QTableWidgetItem(name));
        ui->childrenTable->setItem(rowCount, 1, new QTableWidgetItem(QString::number(age)));
        ui->childrenTable->setItem(rowCount, 2, new QTableWidgetItem(genderStr));
        ui->childrenTable->setItem(rowCount, 3, new QTableWidgetItem(QString::number(goodDeeds)));
        ui->childrenTable->setItem(rowCount, 4, new QTableWidgetItem(QString::number(badDeeds)));
        ui->childrenTable->setItem(rowCount, 5, new QTableWidgetItem(giftTypeStr));
        ui->childrenTable->setItem(rowCount, 6, new QTableWidgetItem(specificGift));
    }

    file.close();
}



void MainWindow::addChildToTable(const Child& child)
{
    messageManager.addMessage(new Child(child));

    QVector<Child*> uniqueChildren = messageManager.getUniqueMessages();

    ui->childrenTable->setRowCount(0);

    QFile file("C:/Users/Admin/Desktop/CourseWok/children.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }

    QTextStream out(&file);

    for (Child* uniqueChild : uniqueChildren) {
        int rowCount = ui->childrenTable->rowCount();
        ui->childrenTable->insertRow(rowCount);

        ui->childrenTable->setItem(rowCount, 0, new QTableWidgetItem(uniqueChild->getName()));
        ui->childrenTable->setItem(rowCount, 1, new QTableWidgetItem(QString::number(uniqueChild->getAge())));
        ui->childrenTable->setItem(rowCount, 2, new QTableWidgetItem(uniqueChild->getGender() == Child::Gender::Male ? "Хлопець" : "Дівчина"));
        ui->childrenTable->setItem(rowCount, 3, new QTableWidgetItem(QString::number(uniqueChild->getGoodDeeds())));
        ui->childrenTable->setItem(rowCount, 4, new QTableWidgetItem(QString::number(uniqueChild->getBadDeeds())));

        QString giftTypeString = (uniqueChild->getGiftType() == Child::GiftType::Edible) ? "Їстівний" : "Неїстівний";
        ui->childrenTable->setItem(rowCount, 5, new QTableWidgetItem(giftTypeString));
        ui->childrenTable->setItem(rowCount, 6, new QTableWidgetItem(uniqueChild->getSpecificGift()));

        out << uniqueChild->getName() << " "
            << uniqueChild->getAge() << " "
            << (uniqueChild->getGender() == Child::Gender::Male ? "Хлопець" : "Дівчина") << " "
            << uniqueChild->getGoodDeeds() << " "
            << uniqueChild->getBadDeeds() << " "
            << giftTypeString << " "
            << uniqueChild->getSpecificGift() << "\n";
    }

    file.close();
}

void MainWindow::onChildRemoved(const QString& childName)
{
    // Видаляємо повідомлення дитини з MessageManager
    messageManager.removeMessage(childName);

    // Очищуємо таблицю
    ui->childrenTable->setRowCount(0);

    // Отримуємо оновлений список унікальних дітей
    QVector<Child*> uniqueChildren = messageManager.getUniqueMessages();

    // Оновлюємо таблицю та файл після видалення дитини
    QFile file("C:/Users/Admin/Desktop/CourseWok/children.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }

    QTextStream out(&file);

    for (Child* uniqueChild : uniqueChildren) {
        int rowCount = ui->childrenTable->rowCount();
        ui->childrenTable->insertRow(rowCount);

        // Додаємо оновлені дані в таблицю
        ui->childrenTable->setItem(rowCount, 0, new QTableWidgetItem(uniqueChild->getName()));
        ui->childrenTable->setItem(rowCount, 1, new QTableWidgetItem(QString::number(uniqueChild->getAge())));
        ui->childrenTable->setItem(rowCount, 2, new QTableWidgetItem(uniqueChild->getGender() == Child::Gender::Male ? "Хлопець" : "Дівчина"));
        ui->childrenTable->setItem(rowCount, 3, new QTableWidgetItem(QString::number(uniqueChild->getGoodDeeds())));
        ui->childrenTable->setItem(rowCount, 4, new QTableWidgetItem(QString::number(uniqueChild->getBadDeeds())));QString giftTypeString = (uniqueChild->getGiftType() == Child::GiftType::Edible) ? "Їстівний" : "Неїстівний";
ui->childrenTable->setItem(rowCount, 5, new QTableWidgetItem(giftTypeString));
ui->childrenTable->setItem(rowCount, 6, new QTableWidgetItem(uniqueChild->getSpecificGift()));

// Записуємо нові дані в файл
out << uniqueChild->getName() << " "
    << uniqueChild->getAge() << " "
    << (uniqueChild->getGender() == Child::Gender::Male ? "Хлопець" : "Дівчина") << " "
    << uniqueChild->getGoodDeeds() << " "
    << uniqueChild->getBadDeeds() << " "
    << giftTypeString << " "
    << uniqueChild->getSpecificGift() << "\n";
}

file.close();
}




void MainWindow::on_action_2_triggered()
{
    if (!window2) {
        window2 = new Window2(this);
        connect(window2, &Window2::childAdded, this, &MainWindow::addChildToTable);
    }
    window2->show();
}

void MainWindow::on_action_3_triggered()
{
    if (!window3) {
        // Передаємо об'єкт messageManager
        window3 = new Window3(&messageManager, this);
        connect(window3, &Window3::childRemoved, this, &MainWindow::onChildRemoved);
    }
    window3->show();
}


void MainWindow::on_action_5_triggered()
{
    if (!window4) {
        window4 = new Window4(this);
    }
    window4->show();
}


void MainWindow::on_action_4_triggered() {
    if (!window5) {
        window5 = new Window5(&messageManager, this); // Передайте messageManager
    }
    window5->show();
}

void MainWindow::on_pushButton_clicked()
{
     loadChildrenFromFile();  // Виклик функції при натисканні кнопки
}


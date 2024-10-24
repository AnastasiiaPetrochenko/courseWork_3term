#include "window2.h"
#include "ui_window2.h"
#include "child.h"
#include "gift.h"
#include <QMessageBox>

Window2::Window2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Window2)
{
    ui->setupUi(this);
    ui->comboBox_3->hide(); // Сховати comboBox_3 на початку
}

Window2::~Window2()
{
    delete ui;
}

// Метод для отримання рекомендації подарунка
void Window2::showGiftSuggestion(Child::Gender gender)
{
    QString message;
    if (gender == Child::Gender::Male) {
        message = "Для хлопців неїстівний подарунок - це машинка.";
    } else if (gender == Child::Gender::Female) {
        message = "Для дівчат неїстівний подарунок - це лялька.";
    }
    QMessageBox::information(this, "Рекомендація", message);
}

void Window2::on_pushButton_clicked()
{
    // Отримання введених даних
    QString name = ui->lineEdit->text();
    int age = ui->spinBox->value();
    Child::Gender gender = selectedGender;
    int goodDeeds = ui->spinBox_2->value();
    int badDeeds = ui->spinBox_3->value();

    // Визначення типу подарунка (їстівний чи неїстівний)
    Child::GiftType giftType;
    if (ui->comboBox->currentIndex() == 0) { // Їстівний
        giftType = Child::GiftType::Edible;
    } else { // Неїстівний
        giftType = Child::GiftType::NonEdible;

        // Викликаємо рекомендацію подарунка для неїстівного подарунка
        showGiftSuggestion(gender);
    }

    // Створення нового об'єкту Child
    Child newChild(name, age, gender, goodDeeds, badDeeds, giftType, ""); // Ініціалізація без конкретного подарунка

    // Визначаємо індекс для їстівного подарунка
    int edibleGiftIndex = -1;  // Ініціалізація як -1 для випадку неїстівного подарунка
    if (giftType == Child::GiftType::Edible) {
        edibleGiftIndex = ui->comboBox_3->currentIndex();  // Отримуємо індекс з comboBox_3
    }

    // Створення об'єкта Gift з передачею індексу їстівного подарунка
    Gift gift(&newChild, edibleGiftIndex);  // Передаємо вказівник на дитину та індекс їстівного подарунка

    // Отримання назви подарунка
    QString giftName = gift.getGiftName();

    // Оновлення конкретного подарунка для нової дитини
    newChild.setSpecificGift(giftName);

    // Виклик сигналу з переданими даними
    emit childAdded(newChild);

    // Очищення полів після додавання
    ui->lineEdit->clear();
    ui->spinBox->setValue(10);
    ui->spinBox_2->setValue(0);
    ui->spinBox_3->setValue(0);
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_3->hide(); // Сховати comboBox_3 після додавання
}



void Window2::on_comboBox_2_currentIndexChanged(int index)
{
    // Якщо вибрано "Хлопчик", збережіть цю інформацію
    if (index == 0) { // Припустимо, що "Хлопчик" - це перший елемент
        selectedGender = Child::Gender::Male;
    }
    // Якщо вибрано "Дівчинка"
    else if (index == 1) { // Припустимо, що "Дівчинка" - це другий елемент
        selectedGender = Child::Gender::Female;
    }
}

void Window2::on_comboBox_3_currentIndexChanged(int index)
{
    // Логіка для вибору конкретного їстівного подарунка (Цукерки, Печиво, Шоколад)
    if (index == 0) {
        // Цукерки
    } else if (index == 1) {
        // Печиво
    } else if (index == 2) {
        // Шоколад
    }
}

void Window2::on_comboBox_activated(int index)
{
    if (index == 0) { // Їстівний
        ui->comboBox_3->show(); // Показати comboBox для вибору їстівного подарунка
    }
    else if (index == 1) { // Неїстівний
        ui->comboBox_3->hide(); // Сховати comboBox_3
        // Викликаємо рекомендацію для неїстівного подарунка
        showGiftSuggestion(selectedGender);
    }
}


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
    try {
        // Отримання введених даних
        QString name = ui->lineEdit->text().trimmed();

        // Перевірка на порожнє поле або некоректні символи
        if (name.isEmpty()) {
            throw std::invalid_argument("Поле імені не може бути порожнім. Будь ласка, введіть ім'я дитини.");
        }
        if (!name.contains(QRegularExpression("^[A-Za-zА-Яа-яІіЇїЄє]+$"))) {
            throw std::invalid_argument("Поле імені містить недопустимі символи. Використовуйте лише літери.");
        }

        // Отримання віку, кількості добрих і поганих вчинків
        int age = ui->spinBox->value();
        int goodDeeds = ui->spinBox_2->value();
        int badDeeds = ui->spinBox_3->value();

        // Якщо вік некоректний (наприклад, менше 1 року або занадто великий)
        if (age <= 0 || age > 18) {
            throw std::out_of_range("Вік має бути в межах від 1 до 18 років.");
        }

        // Інші перевірки
        Child::Gender gender = selectedGender;

        // Визначення типу подарунка (їстівний чи неїстівний)
        Child::GiftType giftType;
        if (ui->comboBox->currentIndex() == 0) {
            giftType = Child::GiftType::Edible;
        } else {
            giftType = Child::GiftType::NonEdible;
            showGiftSuggestion(gender);
        }

        // Створення нового об'єкту Child
        Child newChild(name, age, gender, goodDeeds, badDeeds, giftType, "");

        // Додаткові операції, пов'язані з подарунком
        int edibleGiftIndex = -1;
        if (giftType == Child::GiftType::Edible) {
            edibleGiftIndex = ui->comboBox_3->currentIndex();
        }

        Gift gift(&newChild, edibleGiftIndex);
        QString giftName = gift.getGiftName();
        newChild.setSpecificGift(giftName);

        emit childAdded(newChild);

        // Очищення полів після додавання
        ui->lineEdit->clear();
        ui->spinBox->setValue(10);
        ui->spinBox_2->setValue(0);
        ui->spinBox_3->setValue(0);
        ui->comboBox->setCurrentIndex(0);
        ui->comboBox_2->setCurrentIndex(0);
        ui->comboBox_3->hide();

    } catch (const std::invalid_argument& e) {
        QMessageBox::warning(this, "Помилка", e.what());
    } catch (const std::out_of_range& e) {
        QMessageBox::warning(this, "Помилка", e.what());
    } catch (...) {
        QMessageBox::warning(this, "Невідома помилка", "Виникла невідома помилка.");
    }
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
    }
}


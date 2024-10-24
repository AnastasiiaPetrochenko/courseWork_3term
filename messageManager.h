#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H

#include <QVector>
#include <QString>
#include "child.h"
#include "gift.h"
#include <QSet>

class MessageManager {
public:
    // Додає нове повідомлення (дитину) до менеджера
    void addMessage(Child* child);

    // Видаляє повідомлення дитини за її ім'ям
    void removeMessage(const QString& childName);

    // Повертає унікальні повідомлення дітей (тільки останнє повідомлення для кожної дитини)
    QVector<Child*> getUniqueMessages() const;

    // Підраховує кількість їстівних подарунків
    int countEdibleGifts() const;

    // Підраховує кількість неїстівних подарунків
    int countNonEdibleGifts() const;

    // Підраховує кількість конкретного типу подарунка (лялька, машинка, цукерки, шоколад тощо)
    int countGiftType(Child::GiftType giftType) const;

    void clearMessages();
    // Підраховує кількість цукерок
    int countCandy() const;

    // Підраховує кількість шоколаду
    int countChocolate() const;

    // Підраховує кількість печива
    int countCookie() const;

    // Підраховує кількість машинок
    int countCar() const;

    // Підраховує кількість ляльок
    int countDoll() const;

    // Генерує подарунки на основі унікальних повідомлень дітей
    QVector<Gift*> generateGifts();

    // Знаходить наймолодших дітей
    QVector<Child*> findYoungestChildren() const;

    // Повертає останнє повідомлення для конкретної дитини за її ім'ям
    Child* findLastMessage(const QString& childName) const;

private:
    QVector<Child*> messages;  // Список повідомлень (дітей)
};

#endif // MESSAGEMANAGER_H

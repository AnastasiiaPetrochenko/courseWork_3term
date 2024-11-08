#include "messageManager.h"
#include <QSet>

void MessageManager::clearMessages() {
    messages.clear();  // Очищаємо вектор повідомлень
}


void MessageManager::addMessage(Child* child) {
    messages.push_back(child);  // Додаємо дитину до вектора повідомлень
}

void MessageManager::removeMessage(const QString& childName) {
    auto it = std::remove_if(messages.begin(), messages.end(), [&](Child* c) {
        return c->getName() == childName;
    });
    messages.erase(it, messages.end());
}

QVector<Child*> MessageManager::getUniqueMessages() const {
    QVector<Child*> uniqueMessages;
    QSet<QString> childNames;  // Використовуємо множину для відстеження імен

    // Проходимо всі повідомлення у зворотному порядку, щоб додати лише останнє
    for (int i = messages.size() - 1; i >= 0; --i) {
        Child* child = messages[i];
        if (!childNames.contains(child->getName())) {
            uniqueMessages.push_back(child);  // Додаємо тільки останнє повідомлення для дитини
            childNames.insert(child->getName());  // Позначаємо, що ця дитина вже додана
        }
    }

    // Оскільки ми пройшли в зворотному порядку, результат необхідно розвернути
    std::reverse(uniqueMessages.begin(), uniqueMessages.end());

    return uniqueMessages;
}

//підрахунок подарунок - різочка
int MessageManager::countSwitch() const {
    int count = 0;
    for (Child* child : messages) {
        if (child->getSpecificGift() == "Різочка") {
            count++;
        }
    }
    return count;
}

//підрахунок подарунку - цукерки
int MessageManager::countCandy() const {
    int count = 0;
    for (Child* child : messages) {
        if (child->getSpecificGift() == "Цукерки" || child->getGiftType() == Child::GiftType::Candy) {
            count++;
        }
    }
    return count;
}

//підрахунки подарунку - шоколад
int MessageManager::countChocolate() const {
    int count = 0;
    for (Child* child : messages) {
        if (child->getSpecificGift()=="Шоколад" || child->getGiftType() == Child::GiftType::Chocolate) {
            count++;
        }
    }
    return count;
}

//підрахунок подарунку - печиво
int MessageManager::countCookie() const {
    int count = 0;
    for (Child* child : messages) {
        if (child->getSpecificGift() == "Печиво" || child->getGiftType()== Child::GiftType::Cookie) {
            count++;
        }
    }
    return count;
}

//підрахунок подарунку - машинка
int MessageManager::countCar() const {
    int count = 0;
    for (Child* child : messages) {
        if (child->getSpecificGift() == "Машинка"||child->getGiftType()== Child::GiftType::Car) {
            count++;
        }
    }
    return count;
}

//підрахунок подарунку - лялька
int MessageManager::countDoll() const {
    int count = 0;
    for (Child* child : messages) {
        if (child->getSpecificGift() == "Лялька"||child->getGiftType()==Child::GiftType::Doll) {
            count++;
        }
    }
    return count;
}


QVector<Gift*> MessageManager::generateGifts() {
    QVector<Gift*> gifts;
    for (Child* child : getUniqueMessages()) {
        gifts.push_back(new Gift(child));  // Приклад створення подарунку для дитини
    }
    return gifts;
}

//підрахунок загальної кількості їстівних подарунків
int MessageManager::countEdibleGifts() const {
    int count = 0;
    for (Child* child : messages) {
        if (child->getGiftType() == Child::GiftType::Edible) {
            count++;
        }
    }
    return count;
}


//підрахунок загальної кількості неїстівних подарунків
int MessageManager::countNonEdibleGifts() const {
    int count = 0;
    for (Child* child : messages) {
        if (child->getGiftType() == Child::GiftType::NonEdible) {
            count++;
        }
    }
    return count;
}

int MessageManager::countGiftType(Child::GiftType giftType) const {
    int count = 0;
    for (Child* child : messages) {
        if (child->getGiftType() == giftType) {
            count++;
        }
    }
    return count;
}


QVector<Child*> MessageManager::findYoungestChildrenFromTable(QTableWidget* table) {
    QVector<Child*> childrenList;

    if (!table || table->rowCount() == 0) {
        return childrenList;
    }

    // Збираємо всіх дітей з таблиці
    for (int row = 0; row < table->rowCount(); ++row) {
        QString name = table->item(row, 0)->text();
        int age = table->item(row, 1)->text().toInt();
        QString genderStr = table->item(row, 2)->text();
        int goodDeeds = table->item(row, 3)->text().toInt();
        int badDeeds = table->item(row, 4)->text().toInt();
        QString giftTypeStr = table->item(row, 5)->text();
        QString specificGift = table->item(row, 6)->text();

        Child::Gender gender = (genderStr == "Хлопець") ? Child::Gender::Male : Child::Gender::Female;
        Child::GiftType giftType = (giftTypeStr == "Їстівний") ? Child::GiftType::Edible : Child::GiftType::NonEdible;

        Child* child = new Child(name, age, gender, goodDeeds, badDeeds, giftType, specificGift);
        childrenList.append(child);
    }

    // Знаходимо найменший вік
    if (childrenList.isEmpty()) {
        return {};
    }

    int youngestAge = childrenList[0]->getAge();
    for (Child* child : childrenList) {
        if (child->getAge() < youngestAge) {
            youngestAge = child->getAge();
        }
    }

    // Вибираємо всіх дітей з найменшим віком
    QVector<Child*> youngestChildren;
    for (Child* child : childrenList) {
        if (child->getAge() == youngestAge) {
            youngestChildren.append(child);
        }
    }

    // Видаляємо зайві об'єкти з пам'яті
    for (Child* child : childrenList) {
        if (child->getAge() != youngestAge) {
            delete child;
        }
    }

    return youngestChildren;
}



Child* MessageManager::findLastMessage(const QString& childName) const {
    Child* lastMessage = nullptr;
    for (Child* child : messages) {
        if (child->getName() == childName) {
            lastMessage = child;
        }
    }
    return lastMessage;
}

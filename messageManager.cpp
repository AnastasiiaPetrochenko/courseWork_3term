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


int MessageManager::countCandy() const {
    int count = 0;
    for (Child* child : messages) {
        if (child->getSpecificGift() == "Цукерки" || child->getGiftType() == Child::GiftType::Candy) {
            count++;
        }
    }
    return count;
}


int MessageManager::countChocolate() const {
    int count = 0;
    for (Child* child : messages) {
        if (child->getSpecificGift()=="Шоколад" || child->getGiftType() == Child::GiftType::Chocolate) {
            count++;
        }
    }
    return count;
}

int MessageManager::countCookie() const {
    int count = 0;
    for (Child* child : messages) {
        if (child->getSpecificGift() == "Печиво" || child->getGiftType()== Child::GiftType::Cookie) {
            count++;
        }
    }
    return count;
}

int MessageManager::countCar() const {
    int count = 0;
    for (Child* child : messages) {
        if (child->getSpecificGift() == "Машинка"||child->getGiftType()== Child::GiftType::Car) {
            count++;
        }
    }
    return count;
}

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

int MessageManager::countEdibleGifts() const {
    int count = 0;
    for (Child* child : messages) {
        if (child->getGiftType() == Child::GiftType::Edible) {
            count++;
        }
    }
    return count;
}



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


QVector<Child*> MessageManager::findYoungestChildren() const {
    QVector<Child*> youngest;
    int minAge = std::numeric_limits<int>::max();

    for (Child* child : messages) {
        if (child->getAge() < minAge) {
            minAge = child->getAge();
            youngest.clear();
            youngest.push_back(child);
        } else if (child->getAge() == minAge) {
            youngest.push_back(child);
        }
    }

    return youngest;
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

#include "gift.h"

Gift::Gift(Child* child, int edibleGiftIndex) : child(child), edibleGiftIndex(edibleGiftIndex) {
    determineGift();
}


Gift::Gift(Child* child) : child(child), edibleGiftIndex(-1) { // -1 означає, що це неїстівний подарунок
    determineGift();
}

void Gift::determineGift() {
    if (child == nullptr) {
        return;
    }

    qDebug() << "Determining gift for child:" << child->getName();

    // Якщо дитина заслуговує на різку
    if (child->deservesSwitch()) {
        giftName = "Різочка";
        child->setGiftType(Child::GiftType::NonEdible); // Встановлюємо різку як неїстівний подарунок
        qDebug() << "Gift determined as: Різочка (неїстівний)";
        return;
    }

    // Якщо встановлений конкретний подарунок
    if (!child->getSpecificGift().isEmpty()) {
        giftName = child->getSpecificGift();  // Використовуємо конкретний подарунок
        qDebug() << "Gift determined as:" << giftName;
        return;
    }

    // Якщо конкретний подарунок не встановлено, визначаємо за загальними правилами
    if (child->getGiftType() == Child::GiftType::Edible) {
        switch (edibleGiftIndex) {
        case 0:
            giftName = "Цукерки";
            break;
        case 1:
            giftName = "Печиво";
            break;
        case 2:
            giftName = "Шоколад";
            break;
        default:
            giftName = "Невідомий їстівний подарунок";
            break;
        }
    } else {
        Child::Gender gender = child->getGender();
        if (gender == Child::Gender::Male) {
            giftName = "Машинка";
        } else {
            giftName = "Лялька";
        }
    }

    qDebug() << "Gift determined as:" << giftName;
}



QString Gift::getGiftName() const {
    return giftName;
}

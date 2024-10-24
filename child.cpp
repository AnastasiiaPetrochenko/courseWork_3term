#include "child.h"


Child::Child(const QString& name, int age, Gender gender, int goodDeeds, int badDeeds, GiftType giftType, const QString& specificGift)
    : name(name), age(age), gender(gender), goodDeeds(goodDeeds), badDeeds(badDeeds), giftType(giftType), specificGift(specificGift) {}  // Додаємо ініціалізацію specificGift

QString Child::getName() const {
    return name;
}

int Child::getAge() const {
    return age;
}

Child::Gender Child::getGender() const {
    return gender;
}

int Child::getGoodDeeds() const {
    return goodDeeds;
}

int Child::getBadDeeds() const {
    return badDeeds;
}

Child::GiftType Child::getGiftType() const {
    return giftType;
}

QString Child::getSpecificGift() const {
    return specificGift;
}


// У класі Child
void Child::setSpecificGift(const QString& giftName) {
    specificGift = giftName;
}


bool Child::deservesSwitch() const {
    return badDeeds > goodDeeds;
}

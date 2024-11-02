#ifndef CHILD_H
#define CHILD_H

#include <QString>

class Child {
public:
    enum class Gender { Male, Female };
    enum class GiftType {
        Edible,
        NonEdible,
        Candy,
        Chocolate,
        Cookie,
        Car,
        Doll
    };

     // Конструктор за замовчуванням

    Child(const QString& name, int age, Gender gender, int goodDeeds, int badDeeds, GiftType giftType, const QString& specificGift);
    ~Child() = default;

    QString getName() const;
    int getAge() const;
    Gender getGender() const;
    int getGoodDeeds() const;
    int getBadDeeds() const;
    GiftType getGiftType() const;


    QString getSpecificGift() const;


    void setSpecificGift(const QString& specificGift);
    void setGiftType(GiftType giftType); // Новий метод


    bool deservesSwitch() const;

private:
    QString name;
    int age;
    Gender gender;
    int goodDeeds;
    int badDeeds;
    GiftType giftType;
    QString specificGift;
};

#endif // CHILD_H

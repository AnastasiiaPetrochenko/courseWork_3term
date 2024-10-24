#ifndef GIFT_H
#define GIFT_H

#include "child.h"
#include <QString>
#include <QDebug>

class Gift {
public:
    // Оновлений конструктор з двома параметрами
    Gift(Child* child, int edibleGiftIndex);
    Gift(Child* child); // Якщо індекс не переданий, буде неїстівний подарунок

    QString getGiftName() const;

private:
    Child* child;
    QString giftName;
    int edibleGiftIndex; // Змінна для зберігання індексу їстівного подарунка

    void determineGift();
};

#endif // GIFT_H

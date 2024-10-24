#ifndef WINDOW3_H
#define WINDOW3_H

#include <QDialog>
#include "messageManager.h"

namespace Ui {
class Window3;
}

class Window3 : public QDialog
{
    Q_OBJECT

public:
    explicit Window3(MessageManager* msgManager, QWidget *parent = nullptr);
    ~Window3();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Window3 *ui;
    MessageManager* msgManager;  // Оголошуємо член для доступу до MessageManager

signals:
    void childRemoved(const QString &childName);

};

#endif // WINDOW3_H

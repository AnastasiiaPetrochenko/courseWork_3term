#ifndef WINDOW5_H
#define WINDOW5_H

#include <QDialog>
#include "messageManager.h" // Додайте цей заголовок

namespace Ui {
class Window5;
}

class Window5 : public QDialog {
    Q_OBJECT

public:
    explicit Window5(MessageManager *manager, QWidget *parent = nullptr); // Додайте параметр
    ~Window5();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Window5 *ui;
    MessageManager *messageManager; // Додайте поле для MessageManager
};

#endif // WINDOW5_H

#ifndef WINDOW6_H
#define WINDOW6_H

#include <QDialog>
#include "messageManager.h"

namespace Ui {
class Window6;
}

class Window6 : public QDialog
{
    Q_OBJECT

public:
    explicit Window6(MessageManager* manager, QWidget *parent = nullptr);
    ~Window6();

public:
   // void displayYoungestChildren(const QVector<Child*>& youngestChildren);


private slots:

    void on_pushButton_clicked();

private:
    Ui::Window6 *ui;
    MessageManager* messageManager;

};

#endif // WINDOW6_H

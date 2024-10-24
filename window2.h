#ifndef WINDOW2_H
#define WINDOW2_H

#include <QDialog>
#include "child.h"

namespace Ui {
class Window2;
}

class Window2 : public QDialog
{
    Q_OBJECT

public:
    explicit Window2(QWidget *parent = nullptr);
    ~Window2();

private slots:
    void showGiftSuggestion(Child::Gender gender);

    void on_pushButton_clicked();
    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_comboBox_activated(int index);

signals:
    void childAdded(const Child& child);


private:
    Ui::Window2 *ui;
    Child::Gender selectedGender;
};

#endif // WINDOW2_H

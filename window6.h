#ifndef WINDOW6_H
#define WINDOW6_H

#include <QDialog>

namespace Ui {
class Window6;
}

class Window6 : public QDialog
{
    Q_OBJECT

public:
    explicit Window6(QWidget *parent = nullptr);
    ~Window6();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Window6 *ui;
};

#endif // WINDOW6_H

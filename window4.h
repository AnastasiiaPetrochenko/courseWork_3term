#ifndef WINDOW4_H
#define WINDOW4_H

#include <QDialog>

namespace Ui {
class Window4;
}

class Window4 : public QDialog
{
    Q_OBJECT

public:
    explicit Window4(QWidget *parent = nullptr);
    ~Window4();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Window4 *ui;
};

#endif // WINDOW4_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "child.h"           // Включаємо клас Child
#include "messageManager.h"  // Включаємо MessageManager
#include "window2.h"         // Включаємо Window2
#include "window3.h"         // Включаємо Window3
#include "window4.h"         // Включаємо Window3
#include "window5.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Слот для додавання дитини в таблицю
    void addChildToTable(const Child& child);

    // Слот для відкриття Window2
    void on_action_2_triggered();

    // Слот для відкриття Window3
    void on_action_3_triggered();

    // Слот для обробки видалення дитини
    void onChildRemoved(const QString& childName);

    void on_action_5_triggered();

    void on_action_4_triggered();


    void loadChildrenFromFile();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;         // Інтерфейс головного вікна
    MessageManager messageManager; // Об'єкт MessageManager для управління повідомленнями
    Window2 *window2;           // Вказівник на вікно Window2
    Window3 *window3;           // Вказівник на вікно Window3
    Window4 *window4;
    Window5 *window5;

};

#endif // MAINWINDOW_H

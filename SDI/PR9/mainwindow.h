#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "song.h" // Підключаємо наш клас

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_create_clicked(); // Кнопка
    void on_actionExit_triggered(); // Меню
    void on_actionShow_triggered(); // Меню
    void on_actionCreate_triggered(); // Меню

private:
    Ui::MainWindow *ui;
    Song* currentSong; // Вказівник на об'єкт
};
#endif // MAINWINDOW_H

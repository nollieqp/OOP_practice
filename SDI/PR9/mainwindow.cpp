#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox> // Для повідомлень

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentSong = nullptr;

    // Зв'язуємо пункт меню "Створити" з кнопкою
    connect(ui->actionCreate, &QAction::triggered, this, &MainWindow::on_btn_create_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (currentSong != nullptr) {
        delete currentSong;
    }
}

void MainWindow::on_btn_create_clicked()
{
    // Отримуємо дані
    int id = ui->sb_id->value();
    QString title = ui->le_title->text();
    QString performer = ui->le_performer->text();
    int year = ui->sb_year->value();
    int duration = ui->sb_duration->value();

    // Валідація (чи заповнені поля)
    if (title.isEmpty() || performer.isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Будь ласка, заповніть Назву та Виконавця!");
        return;
    }

    // Створюємо об'єкт (видаляємо старий, якщо був)
    if (currentSong != nullptr) delete currentSong;

    // toStdString() конвертує QString у string
    currentSong = new Song(id, title.toStdString(), performer.toStdString(), year, duration);

    // Показуємо результат
    QString info = QString::fromStdString(currentSong->toString());
    QMessageBox::information(this, "Успіх", "Об'єкт успішно створено!\n\n" + info);
}

void MainWindow::on_actionShow_triggered()
{
    if (currentSong != nullptr) {
        QString info = QString::fromStdString(currentSong->toString());
        QMessageBox::information(this, "Поточний об'єкт", info);
    } else {
        QMessageBox::information(this, "Інфо", "Об'єкт ще не створено.");
    }
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionCreate_triggered()
{
    // Цей метод викликається через connect у конструкторі,
    // але для чистоти можна залишити порожнім або перенаправити
    on_btn_create_clicked();
}

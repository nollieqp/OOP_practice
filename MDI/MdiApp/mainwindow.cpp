#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DialogCreateSong.h"
#include "DialogCreateBook.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1. Підключаємось до БД
    dbManager = SqliteDBManager::getInstance();
    dbManager->connectToDataBase();

    // 2. Створюємо вікна списків
    dialogListSongs = new DialogList("Songs", this);
    dialogListSongs->setWindowTitle("Список Пісень (БД)");

    dialogListBooks = new DialogList("Books", this);
    dialogListBooks->setWindowTitle("Список Книг (БД)");

    // 3. Підключаємо кнопки (Signals & Slots)
    // Якщо ти назвав кнопки у .ui файлі правильно (btnCreateSong і т.д.),
    // то можна використовувати connect:

    connect(ui->btnCreateSong, &QPushButton::clicked, this, &MainWindow::openCreateSong);
    connect(ui->btnCreateBook, &QPushButton::clicked, this, &MainWindow::openCreateBook);

    connect(ui->btnShowSongs, &QPushButton::clicked, this, &MainWindow::toggleSongList);
    connect(ui->btnShowBooks, &QPushButton::clicked, this, &MainWindow::toggleBookList);

    connect(ui->btnExit, &QPushButton::clicked, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
    // dialogListSongs і dialogListBooks видаляться автоматично, бо мають this як parent
}

// --- СЛОТИ (Методи, яких не вистачало) ---

void MainWindow::openCreateSong() {
    DialogCreateSong dlg;
    connect(&dlg, &DialogCreateSong::sendObject, this, &MainWindow::getNewSong);
    dlg.exec(); // Модальне відкриття
}

void MainWindow::openCreateBook() {
    DialogCreateBook dlg;
    connect(&dlg, &DialogCreateBook::sendObject, this, &MainWindow::getNewBook);
    dlg.exec();
}

void MainWindow::getNewSong(Song* s) {
    if(dbManager->insertIntoTable(*s)) {
        dialogListSongs->refresh(); // Оновити таблицю
    }
    delete s;
}

void MainWindow::getNewBook(Audiobook* b) {
    if(dbManager->insertIntoTable(*b)) {
        dialogListBooks->refresh();
    }
    delete b;
}

void MainWindow::toggleSongList() {
    if (dialogListSongs->isVisible())
        dialogListSongs->hide();
    else
        dialogListSongs->show();
}

void MainWindow::toggleBookList() {
    if (dialogListBooks->isVisible())
        dialogListBooks->hide();
    else
        dialogListBooks->show();
}

#include "mainwindow.h"
#include "DialogCreateSong.h"
#include "DialogCreateBook.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("MDI Application (PR10)");
    resize(400, 300);

    // Створюємо вікна списків (але поки не показуємо)
    dialogListSongs = new DialogList("Список Пісень", this);
    dialogListBooks = new DialogList("Список Книг", this);

    // Створюємо інтерфейс головного вікна
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QPushButton *btnCreateSong = new QPushButton("Створити Пісню", this);
    QPushButton *btnCreateBook = new QPushButton("Створити Книгу", this);
    QPushButton *btnShowSongs = new QPushButton("Показати/Приховати Пісні", this);
    QPushButton *btnShowBooks = new QPushButton("Показати/Приховати Книги", this);
    QPushButton *btnExit = new QPushButton("Вихід", this);

    layout->addWidget(btnCreateSong);
    layout->addWidget(btnCreateBook);
    layout->addSpacing(20);
    layout->addWidget(btnShowSongs);
    layout->addWidget(btnShowBooks);
    layout->addSpacing(20);
    layout->addWidget(btnExit);

    // Підключаємо кнопки
    connect(btnCreateSong, &QPushButton::clicked, this, &MainWindow::openCreateSong);
    connect(btnCreateBook, &QPushButton::clicked, this, &MainWindow::openCreateBook);
    connect(btnShowSongs, &QPushButton::clicked, this, &MainWindow::toggleSongList);
    connect(btnShowBooks, &QPushButton::clicked, this, &MainWindow::toggleBookList);
    connect(btnExit, &QPushButton::clicked, this, &MainWindow::close);
}

MainWindow::~MainWindow() {}

// --- Логіка Створення ---

void MainWindow::openCreateSong() {
    DialogCreateSong dlg; // Модальне вікно
    // З'єднуємо сигнал діалогу зі слотом головного вікна
    connect(&dlg, &DialogCreateSong::sendObject, this, &MainWindow::getNewSong);
    dlg.exec(); // Запускаємо модально
}

void MainWindow::openCreateBook() {
    DialogCreateBook dlg;
    connect(&dlg, &DialogCreateBook::sendObject, this, &MainWindow::getNewBook);
    dlg.exec();
}

// --- Логіка Отримання даних ---

void MainWindow::getNewSong(Song* s) {
    songs.push_back(s);
    // Додаємо в вікно списку
    dialogListSongs->addItem(QString::fromStdString(s->toString()));
}

void MainWindow::getNewBook(Audiobook* b) {
    books.push_back(b);
    dialogListBooks->addItem(QString::fromStdString(b->toString()));
}

// --- Логіка Відображення списків ---

void MainWindow::toggleSongList() {
    if (dialogListSongs->isVisible())
        dialogListSongs->hide();
    else
        dialogListSongs->show(); // Немодальний показ
}

void MainWindow::toggleBookList() {
    if (dialogListBooks->isVisible())
        dialogListBooks->hide();
    else
        dialogListBooks->show();
}

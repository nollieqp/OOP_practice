#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "Song.h"
#include "Audiobook.h"
#include "DialogList.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openCreateSong();
    void openCreateBook();

    void getNewSong(Song* s);      // Слот отримання пісні
    void getNewBook(Audiobook* b); // Слот отримання книги

    void toggleSongList();
    void toggleBookList();

private:
    // Контейнери даних
    std::vector<Song*> songs;
    std::vector<Audiobook*> books;

    // Вказівники на вікна списків (щоб відкривати/закривати ті самі вікна)
    DialogList* dialogListSongs;
    DialogList* dialogListBooks;
};
#endif

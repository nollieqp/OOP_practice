#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>        // <-- Цього не вистачало
#include "DialogList.h"       // <-- Цього не вистачало
#include "SqliteDBManager.h"
#include "Song.h"
#include "Audiobook.h"

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
    void openCreateSong();
    void openCreateBook();

    void getNewSong(Song* s);
    void getNewBook(Audiobook* b);

    void toggleSongList();
    void toggleBookList();

private:
    Ui::MainWindow *ui;
    DialogList* dialogListSongs;
    DialogList* dialogListBooks;
    SqliteDBManager* dbManager;
};
#endif // MAINWINDOW_H

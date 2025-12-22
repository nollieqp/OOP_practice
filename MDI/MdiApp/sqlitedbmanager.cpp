#include "SqliteDBManager.h"
#include <QStandardPaths>
#include <QDir>

SqliteDBManager* SqliteDBManager::getInstance() {
    static SqliteDBManager instance;
    return &instance;
}

SqliteDBManager::SqliteDBManager() {}

void SqliteDBManager::connectToDataBase() {
    // Створюємо файл БД у папці документів користувача
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    path.append("/media_library.sqlite");

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if (!db.open()) {
        qDebug() << "Error connection to DB:" << db.lastError().text();
    } else {
        qDebug() << "DB connected to:" << path;
        createTables();
    }
}

QSqlDatabase SqliteDBManager::getDB() {
    return db;
}

bool SqliteDBManager::createTables() {
    QSqlQuery query;

    // Таблиця для пісень
    QString strSong = "CREATE TABLE IF NOT EXISTS Songs ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "title TEXT, "
                      "performer TEXT, "
                      "year INTEGER);";

    // Таблиця для книг
    QString strBook = "CREATE TABLE IF NOT EXISTS Books ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "title TEXT, "
                      "author TEXT, "
                      "year INTEGER);";

    if (!query.exec(strSong) || !query.exec(strBook)) {
        qDebug() << "Error creating tables:" << query.lastError().text();
        return false;
    }
    return true;
}

bool SqliteDBManager::insertIntoTable(const Song& song) {
    QSqlQuery query;
    query.prepare("INSERT INTO Songs (title, performer, year) VALUES (:title, :perf, :year)");
    query.bindValue(":title", QString::fromStdString(song.getTitle()));
    query.bindValue(":perf", QString::fromStdString(song.getPerformer()));
    query.bindValue(":year", song.getYear());

    if(!query.exec()){
        qDebug() << "Error inserting song:" << query.lastError().text();
        return false;
    }
    return true;
}

bool SqliteDBManager::insertIntoTable(const Audiobook& book) {
    QSqlQuery query;
    query.prepare("INSERT INTO Books (title, author, year) VALUES (:title, :auth, :year)");
    query.bindValue(":title", QString::fromStdString(book.getTitle()));
    query.bindValue(":auth", QString::fromStdString(book.getAuthor()));
    query.bindValue(":year", book.getYear());

    if(!query.exec()){
        qDebug() << "Error inserting book:" << query.lastError().text();
        return false;
    }
    return true;
}

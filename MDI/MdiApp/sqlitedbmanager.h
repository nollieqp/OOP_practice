#ifndef SQLITEDBMANAGER_H
#define SQLITEDBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "Song.h"
#include "Audiobook.h"

class SqliteDBManager
{
public:
    static SqliteDBManager* getInstance();

    void connectToDataBase();
    QSqlDatabase getDB();
    bool createTables();

    // Методи для вставки даних
    bool insertIntoTable(const Song& song);
    bool insertIntoTable(const Audiobook& book);

private:
    SqliteDBManager(); // Приватний конструктор (Singleton)
    QSqlDatabase db;
};

#endif // SQLITEDBMANAGER_H

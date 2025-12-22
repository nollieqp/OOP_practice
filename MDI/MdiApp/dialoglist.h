#ifndef DIALOGLIST_H
#define DIALOGLIST_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class DialogList;
}

class DialogList : public QDialog
{
    Q_OBJECT

public:
    // Передаємо назву таблиці в БД ("Songs" або "Books")
    explicit DialogList(QString dbTableName, QWidget *parent = nullptr);
    ~DialogList();

    // Метод для оновлення даних
    void refresh();

private:
    Ui::DialogList *ui;
    QSqlTableModel *model;
};

#endif // DIALOGLIST_H

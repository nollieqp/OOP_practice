#ifndef DIALOGLIST_H
#define DIALOGLIST_H

#include <QDialog>
#include <QListWidget>

class DialogList : public QDialog {
    Q_OBJECT
public:
    explicit DialogList(QString title, QWidget *parent = nullptr);
    void addItem(QString text); // Метод для додавання рядка

private:
    QListWidget *listWidget;
};
#endif

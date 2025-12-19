#include "DialogList.h"
#include <QVBoxLayout>

DialogList::DialogList(QString title, QWidget *parent) : QDialog(parent) {
    setWindowTitle(title);
    setModal(false); // Немодальне вікно!
    resize(300, 400);

    listWidget = new QListWidget(this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(listWidget);
}

void DialogList::addItem(QString text) {
    listWidget->addItem(text);
}

#include "DialogCreateBook.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QMessageBox>

DialogCreateBook::DialogCreateBook(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Створити Книгу");
    setModal(true);

    leTitle = new QLineEdit(this);
    leAuthor = new QLineEdit(this);
    sbYear = new QSpinBox(this);
    sbYear->setRange(1900, 2030);
    sbYear->setValue(2023);

    QPushButton *btnCreate = new QPushButton("Створити", this);
    connect(btnCreate, &QPushButton::clicked, this, &DialogCreateBook::onCreateClicked);

    QFormLayout *form = new QFormLayout();
    form->addRow("Назва:", leTitle);
    form->addRow("Автор:", leAuthor);
    form->addRow("Рік:", sbYear);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(form);
    mainLayout->addWidget(btnCreate);
}

void DialogCreateBook::onCreateClicked() {
    if(leTitle->text().isEmpty() || leAuthor->text().isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Заповніть всі поля!");
        return;
    }
    Audiobook* b = new Audiobook(leTitle->text().toStdString(),
                                 leAuthor->text().toStdString(),
                                 sbYear->value());
    emit sendObject(b);
    accept();
}

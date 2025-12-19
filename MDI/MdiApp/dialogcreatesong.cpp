#include "DialogCreateSong.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QMessageBox>

DialogCreateSong::DialogCreateSong(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Створити Пісню");
    setModal(true); // Робимо модальним

    leTitle = new QLineEdit(this);
    lePerformer = new QLineEdit(this);
    sbYear = new QSpinBox(this);
    sbYear->setRange(1900, 2030);
    sbYear->setValue(2023);

    QPushButton *btnCreate = new QPushButton("Створити", this);
    connect(btnCreate, &QPushButton::clicked, this, &DialogCreateSong::onCreateClicked);

    QFormLayout *form = new QFormLayout();
    form->addRow("Назва:", leTitle);
    form->addRow("Виконавець:", lePerformer);
    form->addRow("Рік:", sbYear);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(form);
    mainLayout->addWidget(btnCreate);
}

void DialogCreateSong::onCreateClicked() {
    if(leTitle->text().isEmpty() || lePerformer->text().isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Заповніть всі поля!");
        return;
    }
    // Створюємо об'єкт і відправляємо сигнал
    Song* s = new Song(leTitle->text().toStdString(),
                       lePerformer->text().toStdString(),
                       sbYear->value());
    emit sendObject(s);
    accept(); // Закриваємо вікно
}

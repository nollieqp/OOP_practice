#ifndef DIALOGCREATEBOOK_H
#define DIALOGCREATEBOOK_H

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include "Audiobook.h"

class DialogCreateBook : public QDialog {
    Q_OBJECT
public:
    explicit DialogCreateBook(QWidget *parent = nullptr);

signals:
    void sendObject(Audiobook* b);

private slots:
    void onCreateClicked();

private:
    QLineEdit *leTitle;
    QLineEdit *leAuthor;
    QSpinBox *sbYear;
};
#endif

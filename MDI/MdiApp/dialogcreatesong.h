#ifndef DIALOGCREATESONG_H
#define DIALOGCREATESONG_H

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include "Song.h"

class DialogCreateSong : public QDialog {
    Q_OBJECT
public:
    explicit DialogCreateSong(QWidget *parent = nullptr);

signals:
    void sendObject(Song* s); // Сигнал повернення об'єкта

private slots:
    void onCreateClicked();

private:
    QLineEdit *leTitle;
    QLineEdit *lePerformer;
    QSpinBox *sbYear;
};
#endif

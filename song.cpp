#include "song.h"
#include <iostream>
#include <string>

using namespace std;

song::song() : AudioMedia(), performer("Unknown"), genre("-") {}

song::song(int id, string title, string performer, string genre, int year, int duration)
    : AudioMedia(id, title, year, duration), performer(performer), genre(genre) {
}

void song::printInfo() const {
    cout << "[SONG] ID: " << id << " | Title: " << title
        << " (" << year << ") | " << duration << " sec" << endl;
    cout << "       Performer: " << performer << " | Genre: " << genre << endl;
}

istream& operator>>(istream& is, song& s) {
    cout << "\n[Введення Пісні]\n";
    cout << "ID: "; is >> s.id; is.ignore();
    cout << "Назва: "; getline(is, s.title);
    cout << "Виконавець: "; getline(is, s.performer);
    cout << "Жанр: "; getline(is, s.genre);
    cout << "Рік: "; is >> s.year;
    cout << "Тривалість (сек): "; is >> s.duration;
    return is;
}
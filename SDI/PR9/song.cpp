#include "song.h"

Song::Song() : id(0), title(""), performer(""), year(0), duration(0) {}

Song::Song(int id, string title, string performer, int year, int duration)
    : id(id), title(title), performer(performer), year(year), duration(duration) {}

string Song::toString() const {
    return "ID: " + to_string(id) +
           "\nНазва: " + title +
           "\nВиконавець: " + performer +
           "\nРік: " + to_string(year) +
           "\nТривалість: " + to_string(duration) + " сек.";
}

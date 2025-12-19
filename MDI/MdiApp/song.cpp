#include "Song.h"

Song::Song(string title, string performer, int year)
    : AudioMedia(title, year), performer(performer) {}

string Song::toString() const {
    return "[Song] " + title + " - " + performer + " (" + to_string(year) + ")";
}

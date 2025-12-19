#include "Audiobook.h"

Audiobook::Audiobook(string title, string author, int year)
    : AudioMedia(title, year), author(author) {}

string Audiobook::toString() const {
    return "[Book] " + title + " (Auth: " + author + ", " + to_string(year) + ")";
}

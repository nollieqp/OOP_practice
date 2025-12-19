#include "song.h"

song::song() : AudioMedia(), performer("Unknown"), album("-"), genre("-"), lyricist("-"), language("-") {}

song::song(int id, string title, string performer, string album, string genre,
    string lyricist, string language, int year, int durationseconds)
    : AudioMedia(id, title, year, durationseconds),
    performer(performer), album(album), genre(genre), lyricist(lyricist), language(language) {
}

song::song(const song& other)
    : AudioMedia(other.id, other.title, other.year, other.durationSeconds),
    performer(other.performer), album(other.album), genre(other.genre),
    lyricist(other.lyricist), language(other.language) {
}

song::~song() {}

string song::getPerformer() { return performer; }
string song::getAlbum() { return album; }
string song::getGenre() { return genre; }
string song::getLyricist() { return lyricist; }
string song::getLanguage() { return language; }

void song::setPerformer(string performer) { this->performer = performer; }
void song::setAlbum(string album) { this->album = album; }
void song::setGenre(string genre) { this->genre = genre; }
void song::setLyricist(string lyricist) { this->lyricist = lyricist; }
void song::setLanguage(string language) { this->language = language; }

void song::printInfo() const {
    cout << "[SONG] ";
    AudioMedia::printInfo();
    cout << "       Performer: " << performer << ", Album: " << album << endl;
}

bool song::operator==(const song& other) const {
    return (this->id == other.id && this->title == other.title && this->performer == other.performer);
}

ostream& operator<<(ostream& os, const song& s) {
    os << "Song ID: " << s.id << " | Title: " << s.title << " | Performer: " << s.performer;
    return os;
}

istream& operator>>(istream& is, song& s) {
    cout << "Enter Song ID: "; is >> s.id; is.ignore();
    cout << "Enter Title: "; getline(is, s.title);
    cout << "Enter Performer: "; getline(is, s.performer);
    cout << "Enter Year: "; is >> s.year;
    cout << "Enter Duration: "; is >> s.durationSeconds;
    return is;
}
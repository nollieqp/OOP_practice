#include "song.h"
#include <string>
#include <iostream>

song::song()
    : id(0), title("Empty"), performer("Unknown"), album("-"),
    genre("-"), lyricist("-"), language("-"),
    year(0), durationseconds(0) {
}

song::song(int id, std::string title, std::string performer, std::string album,
    std::string genre, std::string lyricist, std::string language,
    int year, int durationseconds)
    : id(id), title(title), performer(performer), album(album),
    genre(genre), lyricist(lyricist), language(language),
    year(year), durationseconds(durationseconds) {
}

song::song(const song& other)
    : id(other.id), title(other.title), performer(other.performer),
    album(other.album), genre(other.genre), lyricist(other.lyricist),
    language(other.language), year(other.year),
    durationseconds(other.durationseconds) {
}

song::~song() {}

int song::getId() { return id; }
std::string song::getTitle() { return title; }
std::string song::getPerformer() { return performer; }
std::string song::getAlbum() { return album; }
std::string song::getGenre() { return genre; }
std::string song::getLyricist() { return lyricist; }
std::string song::getLanguage() { return language; }
int song::getYear() { return year; }
int song::getDurationseconds() { return durationseconds; }

void song::setId(int id) { this->id = id; }
void song::setTitle(std::string title) { this->title = title; }
void song::setPerformer(std::string performer) { this->performer = performer; }
void song::setAlbum(std::string album) { this->album = album; }
void song::setGenre(std::string genre) { this->genre = genre; }
void song::setLyricist(std::string lyricist) { this->lyricist = lyricist; }
void song::setLanguage(std::string language) { this->language = language; }
void song::setYear(int year) { this->year = year; }
void song::setDurationseconds(int durationseconds) { this->durationseconds = durationseconds; }

bool song::operator==(const song& other) const {
    return (this->id == other.id &&
        this->title == other.title &&
        this->performer == other.performer &&
        this->year == other.year);
}

std::ostream& operator<<(std::ostream& os, const song& s) {
    os << "--- Song Info ---\n"
        << "ID: " << s.id << " | Title: " << s.title << "\n"
        << "Performer: " << s.performer << " (" << s.year << ")\n"
        << "Album: " << s.album << " | Genre: " << s.genre << "\n"
        << "Duration: " << s.durationseconds << " sec\n";
    return os;
}

std::istream& operator>>(std::istream& is, song& s) {
    std::cout << "\n[Введення даних пісні]\n";

    std::cout << "ID: ";
    is >> s.id;
    is.ignore();

    std::cout << "Назва: ";
    getline(is, s.title);

    std::cout << "Виконавець: ";
    getline(is, s.performer);

    std::cout << "Альбом: ";
    getline(is, s.album);

    std::cout << "Жанр: ";
    getline(is, s.genre);

    std::cout << "Автор тексту: ";
    getline(is, s.lyricist);

    std::cout << "Мова: ";
    getline(is, s.language);

    std::cout << "Рік: ";
    is >> s.year;

    std::cout << "Тривалість (сек): ";
    is >> s.durationseconds;

    return is;
}
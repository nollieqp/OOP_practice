#include "Audiobook.h"

Audiobook::Audiobook() : AudioMedia(), author("-"), publisher("-"), price(0.0), format("mp3") {}

Audiobook::Audiobook(int id, string title, string author, string publisher,
    int year, int duration, double price, string format)
    : AudioMedia(id, title, year, duration),
    author(author), publisher(publisher), price(price), format(format) {
}

Audiobook::~Audiobook() {}

void Audiobook::printInfo() const {
    cout << "[AUDIOBOOK] ";
    AudioMedia::printInfo();
    cout << "            Author: " << author << ", Price: " << price << "$" << endl;
}
#include "Audiobook.h"
#include <iostream>
#include <string>

using namespace std;

Audiobook::Audiobook() : AudioMedia(), author("-"), price(0.0) {}

Audiobook::Audiobook(int id, string title, string author, int year, int duration, double price)
    : AudioMedia(id, title, year, duration), author(author), price(price) {
}

void Audiobook::printInfo() const {
    cout << "[BOOK] ID: " << id << " | Title: " << title
        << " (" << year << ") | " << duration << " sec" << endl;
    cout << "       Author: " << author << " | Price: " << price << "$" << endl;
}

istream& operator>>(istream& is, Audiobook& ab) {
    cout << "\n[Введення Аудіокниги]\n";
    cout << "ID: "; is >> ab.id; is.ignore();
    cout << "Назва: "; getline(is, ab.title);
    cout << "Автор: "; getline(is, ab.author);
    cout << "Рік: "; is >> ab.year;
    cout << "Тривалість (сек): "; is >> ab.duration;
    cout << "Ціна: "; is >> ab.price;
    return is;
}
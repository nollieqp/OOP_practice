#include <iostream>
#include <Windows.h>
#include "song.h"
#include "Audiobook.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== Тестування спадкування ===\n" << endl;

    song mySong(1, "Billie Jean", "Michael Jackson", "Thriller", "Pop", "MJ", "English", 1982, 294);

    Audiobook myBook(101, "The Witcher", "Andrzej Sapkowski", "SuperNowa", 1993, 36000, 15.99, "MP3");

    cout << "Об'єкт класу Song:" << endl;
    mySong.printInfo();

    cout << "\nОб'єкт класу Audiobook:" << endl;
    myBook.printInfo();

    cout << "\n=== Робота завершена успішно ===" << endl;
    return 0;
}
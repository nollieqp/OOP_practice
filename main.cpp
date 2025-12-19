#include <iostream>
#include <Windows.h>
#include "song.h"
#include "Audiobook.h"
#include "MyVector.h" // Підключаємо наш шаблон

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== Практична робота 6: Шаблонний клас Vector ===\n" << endl;

    // --- ЧАСТИНА 1: Тест з простими типами (int) ---
    cout << "[Тест Vector<int>]" << endl;
    Vector<int> intVec;
    intVec.push_back(10);
    intVec.push_back(20);
    intVec.push_back(30);
    intVec.push_back(40);
    intVec.push_back(50);

    cout << "Size: " << intVec.getSize() << ", Capacity: " << intVec.getCapacity() << endl;
    cout << "Елементи: ";
    for (int i = 0; i < intVec.getSize(); i++) {
        cout << intVec[i] << " ";
    }
    cout << "\n\n";

    // --- ЧАСТИНА 2: Тест з числами з комою (double) ---
    cout << "[Тест Vector<double>]" << endl;
    Vector<double> doubleVec;
    doubleVec.push_back(3.14);
    doubleVec.push_back(9.81);
    doubleVec.push_back(2.71);

    cout << "Елементи: ";
    for (int i = 0; i < doubleVec.getSize(); i++) {
        cout << doubleVec[i] << " ";
    }
    cout << "\n\n";

    // --- ЧАСТИНА 3: Тест з нашими класами (Vector<AudioMedia*>) ---
    cout << "[Тест Vector<AudioMedia*>]" << endl;
    Vector<AudioMedia*> mediaLibrary;

    // Додаємо 2 пісні
    mediaLibrary.push_back(new song(1, "Billie Jean", "Michael Jackson", "Pop", 1982, 294));
    mediaLibrary.push_back(new song(2, "Shape of You", "Ed Sheeran", "Pop", 2017, 233));

    // Додаємо 2 книги
    mediaLibrary.push_back(new Audiobook(101, "The Witcher", "A. Sapkowski", 1993, 36000, 15.99));
    mediaLibrary.push_back(new Audiobook(102, "Dune", "Frank Herbert", 1965, 40000, 20.00));

    // Виводимо через цикл (Поліморфізм)
    cout << "--- Вміст медіа-бібліотеки ---" << endl;
    for (int i = 0; i < mediaLibrary.getSize(); i++) {
        mediaLibrary[i]->printInfo(); // Виклик віртуального методу
    }

    // Очищення пам'яті (видаляємо самі об'єкти, вектор видалить тільки масив вказівників)
    for (int i = 0; i < mediaLibrary.getSize(); i++) {
        delete mediaLibrary[i];
    }

    return 0;
}
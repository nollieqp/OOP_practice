#include <iostream>
#include <Windows.h>
#include "song.h"
#include "Audiobook.h"

using namespace std;

void showMenu() {
    cout << "\nОберіть тип об'єкта:" << endl;
    cout << "1. Пісня (Song)" << endl;
    cout << "2. Аудіокнига (Audiobook)" << endl;
    cout << "Ваш вибір: ";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== Практична робота 5: Абстрактні класи ===\n" << endl;

    const int SIZE = 5; // Розмір масиву
    AudioMedia* library[SIZE];

    // Цикл заповнення
    for (int i = 0; i < SIZE; i++) {
        cout << "\n--- Запис №" << (i + 1) << " ---";
        int choice;

        while (true) {
            showMenu();
            cin >> choice;
            if (choice == 1 || choice == 2) break;
            cout << "Помилка! Введіть 1 або 2." << endl;
        }

        if (choice == 1) {
            song* s = new song();
            cin >> *s;
            library[i] = s;
        }
        else {
            Audiobook* b = new Audiobook();
            cin >> *b; // Виклик перевантаженого >>
            library[i] = b;
        }
    }

    // Цикл виведення (Поліморфізм)
    cout << "\n\n=== ВМІСТ БІБЛІОТЕКИ ===" << endl;
    for (int i = 0; i < SIZE; i++) {
        library[i]->printInfo(); // Викличеться правильний метод
    }

    // Очищення пам'яті
    for (int i = 0; i < SIZE; i++) {
        delete library[i];
    }

    return 0;
}
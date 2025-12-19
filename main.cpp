#include <iostream>
#include <list>       // Для std::list
#include <map>        // Для std::map
#include <algorithm>  // Для std::merge
#include <iterator>   // Для std::back_inserter
#include <ctime>      // Для rand
#include <Windows.h>  // Для кирилиці

#include "AudioMedia.h"
#include "song.h"
#include "Audiobook.h"

using namespace std;

// Генератори випадкових чисел
int getRandomOdd() {
    int num = rand() % 100;
    return (num % 2 == 0) ? num + 1 : num;
}

int getRandomEven() {
    int num = rand() % 100;
    return (num % 2 != 0) ? num + 1 : num;
}

void showMenu() {
    cout << "\n--- МЕНЮ ---" << endl;
    cout << "1. Додати Пісню" << endl;
    cout << "2. Додати Аудіокнигу" << endl;
    cout << "3. Знайти об'єкт за ID" << endl;
    cout << "4. Показати всі об'єкти (Iterate Map)" << endl;
    cout << "0. Вихід" << endl;
    cout << "Ваш вибір: ";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    cout << "=== ЗАВДАННЯ 1: Робота з std::list ===" << endl;

    // 1. Створення списків
    list<int> list1;
    list<int> list2;

    // 2. Заповнення списків
    for (int i = 0; i < 10; ++i) list1.push_back(getRandomOdd());
    for (int i = 0; i < 10; ++i) list2.push_back(getRandomEven());

    cout << "Список 1 (непарні): ";
    for (int n : list1) cout << n << " ";
    cout << endl;

    cout << "Список 2 (парні):   ";
    for (int n : list2) cout << n << " ";
    cout << endl;

    // 3. Сортування (для list треба використовувати метод класу, а не std::sort)
    list1.sort();
    list2.sort();

    // 4. Об'єднання (std::merge вимагає Output Iterator, тому back_inserter)
    list<int> list3;
    std::merge(list1.begin(), list1.end(),
        list2.begin(), list2.end(),
        std::back_inserter(list3));

    cout << "Список 3 (merge):   ";
    for (int n : list3) cout << n << " ";
    cout << "\n\n";


    cout << "=== ЗАВДАННЯ 2: Робота з std::map (ID -> Object) ===" << endl;

    // Ключ - int (ID), Значення - вказівник на AudioMedia
    map<int, AudioMedia*> mediaLibrary;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            song* s = new song();
            cin >> *s;
            // Вставка в map. Ключ беремо з об'єкта
            mediaLibrary[s->getId()] = s;
        }
        else if (choice == 2) {
            Audiobook* b = new Audiobook();
            cin >> *b;
            mediaLibrary[b->getId()] = b;
        }
        else if (choice == 3) {
            int searchId;
            cout << "Введіть ID для пошуку: ";
            cin >> searchId;

            // Пошук у map (за ефективністю O(log N))
            auto it = mediaLibrary.find(searchId);

            if (it != mediaLibrary.end()) {
                cout << "\n[ЗНАЙДЕНО]: ";
                // it->first це ключ (ID), it->second це значення (вказівник)
                it->second->printInfo();
            }
            else {
                cout << "\n[ПОМИЛКА]: Об'єкт з таким ID не знайдено." << endl;
            }
        }
        else if (choice == 4) {
            cout << "\n--- Вміст бібліотеки ---" << endl;
            if (mediaLibrary.empty()) cout << "Бібліотека порожня." << endl;

            // Прохід по map ітератором
            for (const auto& pair : mediaLibrary) {
                cout << "Key[" << pair.first << "] -> ";
                pair.second->printInfo();
            }
        }
    }

    // Очищення пам'яті
    for (auto& pair : mediaLibrary) {
        delete pair.second;
    }
    mediaLibrary.clear();

    return 0;
}
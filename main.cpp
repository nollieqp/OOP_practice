#include <iostream>
#include <vector>
#include <algorithm> // Для sort, merge, remove_if
#include <ctime>     // Для rand
#include <Windows.h> // Для кирилиці

// Підключаємо твої класи
#include "AudioMedia.h"
#include "song.h"
#include "Audiobook.h"

using namespace std;

// Допоміжні функції для генерації чисел
int getRandomOdd() {
    int num = rand() % 100;
    return (num % 2 == 0) ? num + 1 : num;
}

int getRandomEven() {
    int num = rand() % 100;
    return (num % 2 != 0) ? num + 1 : num;
}

// Предикати для видалення (визначають тип об'єкта)
bool isSong(AudioMedia* obj) {
    return dynamic_cast<song*>(obj) != nullptr;
}

bool isAudiobook(AudioMedia* obj) {
    return dynamic_cast<Audiobook*>(obj) != nullptr;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    cout << "=== ЗАВДАННЯ 1: Робота з std::vector<int> ===" << endl;

    // 1. Створення векторів
    vector<int> v1(10); // Вектор для непарних
    vector<int> v2(10); // Вектор для парних

    // 2. Заповнення v1 (через індекс)
    cout << "Вектор 1 (непарні, індексація): ";
    for (int i = 0; i < 10; ++i) {
        v1[i] = getRandomOdd();
        cout << v1[i] << " ";
    }
    cout << endl;

    // 2. Заповнення v2 (через ітератор)
    cout << "Вектор 2 (парні, ітератор): ";
    for (auto it = v2.begin(); it != v2.end(); ++it) {
        *it = getRandomEven();
        cout << *it << " ";
    }
    cout << endl;

    // 3. Сортування (обов'язково перед merge)
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    cout << "\nВідсортований Вектор 1: ";
    for (int n : v1) cout << n << " ";
    cout << "\nВідсортований Вектор 2: ";
    for (int n : v2) cout << n << " ";
    cout << endl;

    // 4. Об'єднання (merge)
    vector<int> v3(v1.size() + v2.size()); // Треба виділити пам'ять заздалегідь
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

    cout << "Вектор 3 (об'єднаний std::merge): ";
    for (int n : v3) cout << n << " ";
    cout << "\n\n";


    cout << "=== ЗАВДАННЯ 2: Вектор об'єктів та очищення ===" << endl;

    vector<AudioMedia*> library;
    int choice;

    // Інтерактивне заповнення
    while (true) {
        cout << "Додати об'єкт? (1-Пісня, 2-Книга, 0-Стоп): ";
        cin >> choice;
        if (choice == 0) break;

        if (choice == 1) {
            song* s = new song();
            cin >> *s; // Використовуємо твій перевантажений оператор >>
            library.push_back(s);
        }
        else if (choice == 2) {
            Audiobook* b = new Audiobook();
            cin >> *b;
            library.push_back(b);
        }
    }

    // Створюємо копію вектора
    vector<AudioMedia*> libraryCopy = library;

    cout << "\n--- Початковий вміст (у обох векторах однаковий) ---" << endl;
    for (auto item : library) item->printInfo();

    // 5. Видалення елементів
    // У першому векторі видаляємо Пісні (Subclass 1)
    // erase-remove idiom: стандартний спосіб видалення у C++
    library.erase(
        remove_if(library.begin(), library.end(), isSong),
        library.end()
    );

    // У другому векторі видаляємо Книги (Subclass 2)
    libraryCopy.erase(
        remove_if(libraryCopy.begin(), libraryCopy.end(), isAudiobook),
        libraryCopy.end()
    );

    cout << "\n--- Вектор 1 (Тільки Книги - пісні видалені) ---" << endl;
    if (library.empty()) cout << "(Порожньо)" << endl;
    for (auto item : library) item->printInfo();

    cout << "\n--- Вектор 2 (Тільки Пісні - книги видалені) ---" << endl;
    if (libraryCopy.empty()) cout << "(Порожньо)" << endl;
    for (auto item : libraryCopy) item->printInfo();

    // Примітка: Ми видалили вказівники з векторів, але не звільнили пам'ять (delete).
    // У реальному проекті треба використовувати std::shared_ptr або cleaning loop.
    // Але для лабораторної на алгоритми STL цього достатньо.

    return 0;
}
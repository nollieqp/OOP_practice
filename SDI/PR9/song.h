#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>

using namespace std;

class Song
{
private:
    int id;
    string title;
    string performer;
    int year;
    int duration;

public:
    Song();
    Song(int id, string title, string performer, int year, int duration);

    // Метод для виведення інформації (для завдання)
    string toString() const;
};

#endif // SONG_H

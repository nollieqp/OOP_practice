#ifndef AUDIOMEDIA_H
#define AUDIOMEDIA_H
#include <string>
#include <iostream>

using namespace std;

class AudioMedia {
protected:
    string title;
    int year;
public:
    AudioMedia(string t, int y);
    virtual ~AudioMedia();
    virtual string toString() const = 0; // Суто віртуальний метод
};
#endif

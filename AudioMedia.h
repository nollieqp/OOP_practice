#pragma once
#include <string>
#include <iostream>

using namespace std;

class AudioMedia {
protected:
    int id;
    string title;
    int year;
    int duration;

public:
    AudioMedia();
    AudioMedia(int id, string title, int year, int duration);
    virtual ~AudioMedia();


    virtual void printInfo() const = 0;
};
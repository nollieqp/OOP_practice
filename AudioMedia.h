#pragma once
#include <string>
#include <iostream>

using namespace std;

class AudioMedia {
protected:
    int id;
    string title;
    int year;
    int durationSeconds;

public:
    AudioMedia();
    AudioMedia(int id, string title, int year, int durationSeconds);
    virtual ~AudioMedia();


    int getId() const;
    string getTitle() const;
    int getYear() const;
    int getDuration() const;


    void setId(int id);
    void setTitle(string title);
    void setYear(int year);
    void setDuration(int duration);


    virtual void printInfo() const = 0;
};

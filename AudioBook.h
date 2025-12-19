#pragma once
#include "AudioMedia.h"

class Audiobook : public AudioMedia {
private:
    string author;
    string publisher;
    double price;
    string format;

public:
    Audiobook();
    Audiobook(int id, string title, string author, string publisher,
        int year, int duration, double price, string format);
    ~Audiobook();

    void printInfo() const override;
};
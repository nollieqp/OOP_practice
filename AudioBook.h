#pragma once
#include "AudioMedia.h"

class Audiobook : public AudioMedia {
private:
    string author;
    double price;

public:
    Audiobook();
    Audiobook(int id, string title, string author, int year, int duration, double price);

    void printInfo() const override;

    friend istream& operator>>(istream& is, Audiobook& ab);
};
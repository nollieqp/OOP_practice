#pragma once
#include "AudioMedia.h"

class song : public AudioMedia {
private:
    string performer;
    string genre;

public:
    song();
    song(int id, string title, string performer, string genre, int year, int duration);

    void printInfo() const override;

    friend istream& operator>>(istream& is, song& s);
};
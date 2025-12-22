#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H
#include "AudioMedia.h"

class Audiobook : public AudioMedia {
private:
    string author;
public:
    Audiobook(string title, string author, int year);
    string toString() const override;

    // --- ДОДАЙ ЦЕЙ МЕТОД ---
    string getAuthor() const { return author; }
};
#endif

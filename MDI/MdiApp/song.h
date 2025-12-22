#ifndef SONG_H
#define SONG_H
#include "AudioMedia.h"

class Song : public AudioMedia {
private:
    string performer;
public:
    Song(string title, string performer, int year);
    string toString() const override;

    // --- ДОДАЙ ЦЕЙ МЕТОД ---
    string getPerformer() const { return performer; }
};
#endif

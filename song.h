#pragma once
#include "AudioMedia.h"

class song : public AudioMedia {
private:
    string performer;
    string album;
    string genre;
    string lyricist;
    string language;

public:
    song();
    song(int id, string title, string performer, string album, string genre,
        string lyricist, string language, int year, int durationseconds);
    song(const song& other);
    ~song();

    string getPerformer();
    string getAlbum();
    string getGenre();
    string getLyricist();
    string getLanguage();

    void setPerformer(string performer);
    void setAlbum(string album);
    void setGenre(string Genre);
    void setLyricist(string lyricist);
    void setLanguage(string language);

    void printInfo() const override;

    friend ostream& operator<<(ostream& os, const song& s);
    friend istream& operator>>(istream& is, song& s);
    bool operator==(const song& other) const;
};
#pragma once
#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>

using namespace std;

class song {
private:
    int id;
    string title;
    string performer;
    string album;
    string genre;
    string lyricist;
    string language;
    int year;
    int durationseconds;

public:
    song();
    song(int id, string title, string performer, string album, string genre, string lyricist, string language, int year, int durationseconds);
    song(const song& other);
    ~song();

    int getId();
    string getTitle();
    string getPerformer();
    string getAlbum();
    string getGenre();
    string getLyricist();
    string getLanguage();
    int getYear();
    int getDurationseconds();

    void setId(int id);
    void setTitle(string title);
    void setPerformer(string performer);
    void setAlbum(string album);
    void setGenre(string Genre);
    void setLyricist(string lyricist);
    void setLanguage(string language);
    void setYear(int year);
    void setDurationseconds(int durationseconds);

    bool operator==(const song& other) const;

    friend ostream& operator<<(ostream& os, const song& s);
    friend istream& operator>>(istream& is, song& s);
};

#endif
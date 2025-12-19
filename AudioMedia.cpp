#include "AudioMedia.h"

AudioMedia::AudioMedia() : id(0), title("Unknown"), year(0), durationSeconds(0) {}

AudioMedia::AudioMedia(int id, string title, int year, int durationSeconds)
    : id(id), title(title), year(year), durationSeconds(durationSeconds) {
}

AudioMedia::~AudioMedia() {}

int AudioMedia::getId() const { return id; }
string AudioMedia::getTitle() const { return title; }
int AudioMedia::getYear() const { return year; }
int AudioMedia::getDuration() const { return durationSeconds; }

void AudioMedia::setId(int id) { this->id = id; }
void AudioMedia::setTitle(string title) { this->title = title; }
void AudioMedia::setYear(int year) { this->year = year; }
void AudioMedia::setDuration(int duration) { this->durationSeconds = duration; }

void AudioMedia::printInfo() const {
    cout << "ID: " << id << " | Title: " << title
        << " (" << year << ") | " << durationSeconds << " sec" << endl;
}
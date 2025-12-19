#include "AudioMedia.h"

AudioMedia::AudioMedia() : id(0), title("-"), year(0), duration(0) {}

AudioMedia::AudioMedia(int id, string title, int year, int duration)
    : id(id), title(title), year(year), duration(duration) {
}

AudioMedia::~AudioMedia() {}
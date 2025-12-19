#include <iostream>
#include <Windows.h>
#include "song.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    song song1, song2, song3;

    cout << "=== ÅÒÀÏ 1: Ïåðåâ³ðêà ââåäåííÿ (cin >>) ===" << endl;
    cin >> song1 >> song2 >> song3;

    cout << "\n=== ÅÒÀÏ 2: Ïåðåâ³ðêà âèâåäåííÿ (cout <<) ===" << endl;
    cout << song1 << endl;
    cout << song2 << endl;
    cout << song3 << endl;

    cout << "\n=== ÅÒÀÏ 3: Ïåðåâ³ðêà ïîð³âíÿííÿ (==) ===" << endl;
    if (song1 == song2) {
        cout << "Ðåçóëüòàò: Ï³ñíÿ 1 òà Ï³ñíÿ 2 ²ÄÅÍÒÈ×Í²." << endl;
    }
    else {
        cout << "Ðåçóëüòàò: Ï³ñíÿ 1 òà Ï³ñíÿ 2 Ð²ÇÍ²." << endl;
    }

    if (song1 == song3) {
        cout << "Ðåçóëüòàò: Ï³ñíÿ 1 òà Ï³ñíÿ 3 ²ÄÅÍÒÈ×Í²." << endl;
    }
    else {
        cout << "Ðåçóëüòàò: Ï³ñíÿ 1 òà Ï³ñíÿ 3 Ð²ÇÍ²." << endl;
    }

    return 0;
}
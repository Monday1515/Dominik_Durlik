#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Parrot {
private:
    vector<string> phrases;

public:
    Parrot() {}

    void addPhrase(string phrase) {
        phrases.push_back(phrase);
    }

    void say(int count = 1) const {
        srand(time(0));

        if (phrases.empty()) {
            return;
        }

        string selectedPhrase = phrases[rand() % phrases.size()];

        for (int i = 0; i < count; ++i) {
            cout << selectedPhrase << endl;
        }
    }
};

int main() {
    Parrot myParrot;

    myParrot.addPhrase("1");
    myParrot.addPhrase("2");
    myParrot.addPhrase("3");

    myParrot.say(3);

    return 0;
}
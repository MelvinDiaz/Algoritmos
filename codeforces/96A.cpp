#include <iostream>
using namespace std;
int main() {
    string players;
    bool isDangerous = false;
    cin >> players;
    int count = 1;

    for (int i = 0; i < players.size(); ++i) {
        if (players[i] == players[i + 1])
            ++count;
        else
            count = 1;

        if (count == 7) {
            isDangerous = true;
            break;
        }
    }

    if (isDangerous)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
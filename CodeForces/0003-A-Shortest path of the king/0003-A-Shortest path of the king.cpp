#include <bits/stdc++.h>
using namespace std;

int main() {
    string start, end;
    cin >> start >> end;

    int startI = start[0] - 'a';
    int startJ = start[1] - '1';

    int endI = end[0] - 'a';
    int endJ = end[1] - '1';

    vector<string> moves;
    int dI = endI - startI;
    int dJ = endJ - startJ;

    while (dI != 0 || dJ != 0) {
        string move = "";
        if (dI > 0) {
            move += 'R';
            dI--;
        } else if (dI < 0) {
            move += 'L';
            dI++;
        }
        if (dJ > 0) {
            move += 'U';
            dJ--;
        } else if (dJ < 0) {
            move += 'D';
            dJ++;
        }
        moves.push_back(move);
    }

    cout << moves.size() << endl;
    for (string move : moves) {
        cout << move << endl;
    }

    return 0;
}

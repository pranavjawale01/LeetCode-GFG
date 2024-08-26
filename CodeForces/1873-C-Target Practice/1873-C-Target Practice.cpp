#include <bits/stdc++.h>
using namespace std;

bool first(int i, int j) {
    return (i == 0 && j >= 0 && j <= 9) || (i == 9 && j >= 0 && j <= 9) || (j == 0 && i >= 0 && i <= 9) || (j == 9 && i >= 0 && i <= 9);
}

bool second(int i, int j) {
    return (i == 1 && j >= 1 && j <= 8) || (i == 8 && j >= 1 && j <= 8) || (j == 1 && i >= 1 && i <= 8) || (j == 8 && i >= 1 && i <= 8);
}

bool third(int i, int j) {
    return (i == 2 && j >= 2 && j <= 7) || (i == 7 && j >= 2 && j <= 7) || (j == 2 && i >= 2 && i <= 7) || (j == 7 && i >= 2 && i <= 7);
}

bool fourth(int i, int j) {
    return (i == 3 && j >= 3 && j <= 6) || (i == 6 && j >= 3 && j <= 6) || (j == 3 && i >= 3 && i <= 6) || (j == 6 && i >= 3 && i <= 6);
}

void pranavjawale01() {
    vector<vector<char>> arr(10, vector<char>(10)); 
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> arr[i][j];
        }
    }
    int one = 0, two = 0, three = 0, four = 0, five = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] == 'X') {
                if (first(i, j)) {
                    one++;
                } else if (second(i, j)) {
                    two++;
                } else if (third(i, j)) {
                    three++;
                } else if (fourth(i, j)) {
                    four++;
                } else {
                    five++;
                }
            }
        }
    }
    cout << one * 1 + two * 2 + three * 3 + four * 4 + five * 5 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        pranavjawale01();
    }
    return 0;
}

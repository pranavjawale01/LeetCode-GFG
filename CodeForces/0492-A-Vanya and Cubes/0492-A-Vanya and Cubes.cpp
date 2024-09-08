#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n;
    cin >> n;
    
    int level = 0;
    int totalCubes = 0;
    int cubesForCurrentLevel = 0;
    
    int currentLevel = 1;

    while (true) {
        cubesForCurrentLevel = (currentLevel * (currentLevel + 1)) / 2;

        if (totalCubes + cubesForCurrentLevel > n) {
            break;
        }

        totalCubes += cubesForCurrentLevel;
        level++;
        currentLevel++;
    }
    
    cout << level << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    pranavjawale01();
    
    return 0;
}

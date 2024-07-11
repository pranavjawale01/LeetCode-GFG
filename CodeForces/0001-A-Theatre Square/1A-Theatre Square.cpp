// https://codeforces.com/problemset/problem/1/A

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    long long n, m, a;
    cin >> n >> m >> a;
    
    long long len = ceil((double)(n) / (a));
    long long wid = ceil((double)(m) / (a));
    
    cout << len * wid << endl;
    
    return 0;
}

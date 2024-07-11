#include<bits/stdc++.h>
using namespace std;

bool isRxCy(string s) {
    return s[0] == 'R' && isdigit(s[1]) && s.find('C') != string::npos;
}

string RxCyToCR(string s) {
    int i = 1;
    while (isdigit(s[i])) {
        i++;
    }
    int row = stoi(s.substr(1, i-1));
    int col = stoi(s.substr(i+1));
    
    string colstr = "";
    while (col > 0) {
        col--;
        colstr = char(col % 26 + 'A') + colstr;
        col /= 26;
    }
    return colstr + to_string(row);
}

string CRToRxCy(string s) {
    int i = 0;
    while (isalpha(s[i])) {
        i++;
    }
    string colstr = s.substr(0, i);
    int row = stoi(s.substr(i));
    int col = 0;
    for (char c : colstr) {
        col = col * 26 + (c - 'A' + 1);
    }
    return "R" + to_string(row) + "C" + to_string(col);
}

int main() {
    
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        if (isRxCy(s)) {
            cout << RxCyToCR(s) << endl;
        } else {
            cout << CRToRxCy(s) << endl;
        }
    }
    
    return 0;
}

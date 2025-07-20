//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {
        // Code here
        int a = 0, b = 0;
        int c = 0, d = 0;

        int i = 0;
        while (str[i] != '/') {
            a = a * 10 + (str[i] - '0');
            i++;
        }
        i++;
        while (str[i] != ',') {
            b = b * 10 + (str[i] - '0');
            i++;
        }
        i += 2;

        while (str[i] != '/') {
            c = c * 10 + (str[i] - '0');
            i++;
        }
        i++;
        while (i < str.length()) {
            d = d * 10 + (str[i] - '0');
            i++;
        }

        if (a * d == b * c) {
            return "equal";
        } else if (a * d > b * c) {
            return to_string(a) + "/" + to_string(b);
        } else {
            return to_string(c) + "/" + to_string(d);
        }
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends
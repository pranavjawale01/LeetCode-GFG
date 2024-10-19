//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        int n = str.size();
        if (str[n-1] - '0' <= 5) {
            str[n-1] = '0';
            return str;
        }
        int carry = 1;
        str[n-1] = '0';
        for (int i = n - 2; i >= 0; i--) {
            if (carry) {
                int num = str[i] - '0';
                num++;
                carry = num / 10;
                str[i] = (num % 10) + '0';
            } else {
                break;
            }
        }
        if (carry) {
            char ch = carry + '0';
            str = ch + str;
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends
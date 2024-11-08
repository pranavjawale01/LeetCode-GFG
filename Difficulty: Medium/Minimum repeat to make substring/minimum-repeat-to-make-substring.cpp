//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // code here
        int len1 = s1.size();
        int len2 = s2.size();
        
        if (s1.find_first_not_of(s2) != string::npos && s2.find_first_not_of(s1) != string::npos) {
            return -1;
        }
        
        string repeated = s1;
        int repeatCount = 1;
        
        while (repeated.size() < len2) {
            repeated += s1;
            repeatCount++;
        }
        
        if (repeated.find(s2) != string::npos) {
            return repeatCount;
        }
        
        repeated += s1;
        repeatCount++;
        
        if (repeated.find(s2) != string::npos) {
            return repeatCount;
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends
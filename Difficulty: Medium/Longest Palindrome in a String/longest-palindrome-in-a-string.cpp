//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    string longestPalin(string S) {
        int n = S.length();
        if (n == 0) return "";

        int start = 0;
        int maxlen = 1; 

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && S[left] == S[right]) {
                int currentLength = right - left + 1;
                if (currentLength > maxlen) {
                    start = left;
                    maxlen = currentLength;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            expandAroundCenter(i, i);

            expandAroundCenter(i, i + 1);
        }

        return S.substr(start, maxlen);
    }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
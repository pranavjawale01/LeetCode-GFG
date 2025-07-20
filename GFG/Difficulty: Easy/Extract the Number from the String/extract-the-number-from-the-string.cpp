//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string s) {
        // code here
        int n = s.size();
        long long max_num = -1;
        
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                long long current_num = 0;
                bool contains_nine = false;

                while (i < n && isdigit(s[i])) {
                    if (s[i] == '9') {
                        contains_nine = true;
                    }
                    current_num = current_num * 10 + (s[i] - '0');
                    ++i;
                }

                if (!contains_nine) {
                    max_num = std::max(max_num, current_num);
                }
            }
        }

        return max_num;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends
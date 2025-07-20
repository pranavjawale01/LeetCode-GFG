//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int n = s.length(), m = p.length();
        if (m > n) return "-1";
        int start = -1, end = -1, len = INT_MAX, j = 0, c1 = 0, c2 = 0;
        vector<int> freqS(26, 0), freqP(26, 0);
        for (int i = 0; i < m; i++) {
            freqP[p[i] - 'a']++;
            if (freqP[p[i] - 'a'] == 1) {
                c1++;
            }
        }
        for (int i = 0; i < n; i++) {
            freqS[s[i] - 'a']++;
            if (freqS[s[i] - 'a'] == freqP[s[i] - 'a']) {
                c2++;
            }
            if (c1 == c2) {
                while (freqS[s[j] - 'a'] > freqP[s[j] - 'a']) {
                    freqS[s[j] - 'a']--;
                    j++;
                }
                if (len > i - j + 1) {
                    start = j;
                    end = i;
                    len = i - j + 1;
                }
            }
        }
        if (start == -1) return "-1";
        return s.substr(start, len);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
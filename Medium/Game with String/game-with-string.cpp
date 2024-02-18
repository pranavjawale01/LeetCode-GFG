//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxElement(vector<int>& vec) {
        int max = 0, idx = 0;
        for (int i = 0; i < 26; i++) {
            if (max < vec[i]) {
                max = vec[i];
                idx = i;
            }
        }
        return idx;
    }
    int minValue(string s, int k){
        // code here
        vector<int> vec(26, 0);
        for (char c : s) {
            vec[c - 'a']++;
        }
        int idx = 0;
        for (int i = 0; i < k; i++) {
            idx = maxElement(vec);
            vec[idx]--;
        }
        int sum = 0;
        for (int i = 0; i < 26; i++) {
            sum += vec[i]*vec[i];
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
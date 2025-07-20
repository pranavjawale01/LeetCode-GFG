//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    long long int countOfSubstringWithKOnes(string S, int K){
        //complete the function here
        unordered_map<long long, long long> mp;
        mp[0] = 1;
        long long ans = 0;
        long long sum = 0;
        for (char &c : S) {
            sum += (c == '1') ? 1 : 0;
            if (mp.find(sum - K) != mp.end()) {
                ans += mp[sum - K];
            }
            mp[sum]++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
       string s;
       int k;
       cin >> s >> k;
       Solution ob;
       cout << ob.countOfSubstringWithKOnes(s, k) << endl;
    
cout << "~" << "\n";
}
return 0;
}


// } Driver Code Ends
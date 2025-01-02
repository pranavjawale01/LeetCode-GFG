//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        // code here
        map<pair<long long, long long>, long long> mp;
        mp[{0, 0}] = 1;
        long long zero = 0, one = 0, two = 0;
        long long ans = 0;
        for (char &c : str) {
            if (c == '0') zero++;
            if (c == '1') one++;
            if (c == '2') two++;
            long long onediff = one - zero, twodiff = one - two;
            if (mp.find({onediff, twodiff}) != mp.end()) {
                ans += mp[{onediff, twodiff}];
            }
            mp[{onediff, twodiff}]++;
        }
        return ans;
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
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends
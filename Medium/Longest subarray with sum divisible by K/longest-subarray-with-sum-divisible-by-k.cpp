//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    int sum = 0, rem = 0, mx = 0;
	    unordered_map<int, int> mp;
	    for (int i = 0; i < n; i++) {
	        sum += arr[i];
	        rem = sum % k;
	        if (rem == 0) {
	            mx = max(mx, i+1);
	        }
	        if (rem < 0) {
	            rem += k;
	        }
	        if (mp.find(rem) != mp.end()) {
	            mx = max(mx, i - mp[rem]);
	        } else {
	            mp[rem] = i;
	        }
	    }
	    return mx;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        int low = 0, high = a.size() - 1;
        int ans = INT_MIN;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            ans = max(ans, a[mid]);
            if (mid == 0) {
                low = mid + 1;
            } else if (mid == a.size() - 1) {
                high = mid - 1;
            } else if (a[mid] > a[mid+1]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends
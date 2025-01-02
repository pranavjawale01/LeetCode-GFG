//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        int count0 = 0, count1 = 0, maxCount = 0;
        
        for (char ch : str) {
            if (ch == '0') count0++;
            else if (ch == '1') count1++;
            
            if (count0 == count1) maxCount++;
        }
        
        if (count0 != count1) return -1;
        return maxCount;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int maxSum(int n)
        {
            if (n == 0 || n == 1) {
                return n;
            }
            return max(n, maxSum(n/2) + maxSum(n/3) + maxSum(n/4));
        }
};
// class Solution
// {
// public:
//     unordered_map<int, int> mp;
//     int maxSum(int n)
//     {
//         if (n == 0)
//             return 0;
        
//         if (mp[n]) {
//             return mp[n];
//         }
        
//         int a = maxSum(n / 2);
//         int b = maxSum(n / 3);
//         int c = maxSum(n / 4);
        
//         int maxSumValue = max(n, a + b + c);
        
//         mp[n] = maxSumValue;
        
//         return maxSumValue;
//     }
// };

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }
        
        int setBit = xorSum & ~(xorSum - 1);
        
        int first = 0, second = 0;
        for (int num : nums) {
            if (num & setBit) {
                first ^= num;
            } else {
                second ^= num;
            }
        }
        if (first > second) {
            return {second, first};
        }
        return {first, second};
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
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends
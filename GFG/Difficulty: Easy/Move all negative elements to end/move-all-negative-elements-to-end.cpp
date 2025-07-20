//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        vector<int> result(n);
        int j = 0;
        
        for (int i = 0; i < n; ++i) {
            if (arr[i] >= 0) {
                result[j++] = arr[i];
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (arr[i] < 0) {
                result[j++] = arr[i];
            }
        }
        arr = result;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        ob.segregateElements(nums);

        for (int x : nums)
            cout << x << " ";
        cout << endl;
    }
}
// } Driver Code Ends
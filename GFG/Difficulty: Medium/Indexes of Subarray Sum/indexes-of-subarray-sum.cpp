//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mp;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum == target) {
                return {1, i+1};
            }
            if (mp.find(sum - target) != mp.end()) {
                return {mp[sum - target]+2, i+1};
            }
            mp[sum] = i;
        }
        if (mp.find(sum - target) != mp.end()) {
            return {mp[sum-target]+2, n-1};
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends
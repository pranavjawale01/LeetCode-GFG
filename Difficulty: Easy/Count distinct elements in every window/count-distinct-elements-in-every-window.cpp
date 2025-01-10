//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        vector<int> ans;
        int n = arr.size();
        int i = 0, j = 0;
        unordered_map<int, int> mp;
        while (j < k) {
            mp[arr[j++]]++;
        }
        for (int i = 0; i < n - k + 1; i++) {
            ans.push_back(mp.size());
            mp[arr[j-k]]--;
            if (mp[arr[j-k]] == 0) mp.erase(arr[j-k]);
            mp[arr[j]]++;
            j++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
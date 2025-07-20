//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code
        sort(arr.begin(), arr.end());
        int n = arr.size();
        if (n < 3) return false;
        for (int i = n - 1; i >= 2; i--) {
            int j = i - 1, k = 0;
            while (k < j) {
                int sum = arr[k] + arr[j];
                if (sum == arr[i]) return true;
                else if (sum > arr[i]) j--;
                else k++;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
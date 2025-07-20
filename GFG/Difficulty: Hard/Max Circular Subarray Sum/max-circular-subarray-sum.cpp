//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int kadensAlgoMax(vector<int> &arr) {
        int ans = arr[0], curr = arr[0];
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            curr = max(arr[i], arr[i] + curr);
            ans = max(ans, curr);
        }
        return ans;
    }
    int circularSubarraySum(vector<int> &arr) {
        // your code here
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int ans1 = kadensAlgoMax(arr);
        for (int &x : arr) x = -x;
        int ans2 = kadensAlgoMax(arr);
        ans2 = -ans2;
        if (ans2 == sum) {
            return ans1;
        }
        return max(ans1, sum - ans2);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends
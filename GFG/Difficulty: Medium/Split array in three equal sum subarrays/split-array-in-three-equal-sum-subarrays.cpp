//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
        vector<int> ans;
        int s = accumulate(arr.begin(), arr.end(), 0);
        if (s % 3) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int n = arr.size(), i = 0;
        int s1 = 0;
        while (i < n && s1 < s / 3) {
            s1 += arr[i];
            i++;
        }
        if (s1 == s / 3) {
            if (i != 0) {
                ans.push_back(i-1);
            } else {
                ans.push_back(i);
            }
        } else {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        s1 = 0;
        while (i < n && s1 < s / 3) {
            s1 += arr[i];
            i++;
        }
        if (s1 == s / 3) {
            if (i != 0) {
                ans.push_back(i-1);
            } else {
                ans.push_back(i);
            }
        } else {
            ans[0] = -1;
            ans.push_back(-1);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        vector<int> result = ob.findSplit(arr);

        // Output result
        if (result[0] == -1 && result[1] == -1) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
    }
    return 0;
}

// } Driver Code Ends
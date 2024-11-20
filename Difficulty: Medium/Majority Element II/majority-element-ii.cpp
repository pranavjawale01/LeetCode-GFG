//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        int v1 = 0, v2 = 0, c1 = -1, c2 = -1;

        for (int x : nums) {
            if (v1 == 0 && c2 != x) {
                c1 = x;
                v1 = 1;
            } else if (v2 == 0 && c1 != x) {
                c2 = x;
                v2 = 1;
            } else if (c1 == x) {
                v1++;
            } else if (c2 == x) {
                v2++;
            } else {
                v1--;
                v2--;
            }
        }

        int vc1 = 0, vc2 = 0;
        for (int x : nums) {
            if (x == c1) vc1++;
            if (x == c2) vc2++;
        }

        vector<int> res;
        int n = nums.size();
        if (vc1 > n / 3) res.push_back(c1);
        if (vc2 > n / 3) res.push_back(c2);

        sort(res.begin(), res.end());
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
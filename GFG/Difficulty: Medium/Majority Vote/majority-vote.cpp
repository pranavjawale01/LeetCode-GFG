//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        int vote1 = 0, vote2 = 0, candidate1 = -1, candidate2 = -1;

        for (int x : nums) {
            if (vote1 == 0 && candidate2 != x) {
                candidate1 = x;
                vote1 = 1;
            } else if (vote2 == 0 && candidate1 != x) {
                candidate2 = x;
                vote2 = 1;
            } else if (candidate1 == x) {
                vote1++;
            } else if (candidate2 == x) {
                vote2++;
            } else {
                vote1--;
                vote2--;
            }
        }

        int voteCount1 = 0, voteCount2 = 0;
        for (int x : nums) {
            if (x == candidate1) voteCount1++;
            if (x == candidate2) voteCount2++;
        }

        vector<int> result;
        int n = nums.size();
        if (voteCount1 > n / 3) result.push_back(candidate1);
        if (voteCount2 > n / 3) result.push_back(candidate2);

        return result.empty() ? vector<int>{-1} : result;
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
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
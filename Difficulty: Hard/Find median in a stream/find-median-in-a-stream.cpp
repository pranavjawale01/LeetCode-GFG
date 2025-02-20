//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        priority_queue<int> pql;
        priority_queue<int, vector<int>, greater<>> pqg;
        vector<double> ans;
        for (int x : arr) {
            if (pql.empty() || x <= pql.top()) {
                pql.push(x);
            } else {
                pqg.push(x);
            }
            
            if (pql.size() > pqg.size() + 1) {
                pqg.push(pql.top());
                pql.pop();
            } else if (pqg.size() > pql.size()) {
                pql.push(pqg.top());
                pqg.pop();
            }
            if (pql.size() == pqg.size()) {
                ans.push_back((pql.top() + pqg.top()) / 2.0);
            } else {
                ans.push_back(pql.top());
            }
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

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
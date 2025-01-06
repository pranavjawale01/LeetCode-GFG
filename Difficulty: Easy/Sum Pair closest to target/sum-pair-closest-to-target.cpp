//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int closestSum = INT_MAX;
        int left = 0, right = n - 1;
        int resultLeft = -1, resultRight = -1;
        
        while (left < right) {
            int currentSum = arr[left] + arr[right];
            
            if (abs(currentSum - target) < abs(closestSum - target)) {
                closestSum = currentSum;
                resultLeft = left;
                resultRight = right;
            }
            
            if (currentSum < target) {
                left++;
            } else {
                right--;
            }
        }
        if (resultLeft == -1 || resultRight == -1) {
            vector<int> ans;
            return ans;
        }
        return {arr[resultLeft], arr[resultRight]};
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
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends
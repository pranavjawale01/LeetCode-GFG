//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int m = arr1.size(), n = arr2.size();
        
        if (m > n) return kthElement(k, arr2, arr1);
        
        int low = max(0, k - n), high = min(k, m);
        
        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = k - mid1;
            
            int l1 = (mid1 > 0) ? arr1[mid1 - 1] : INT_MIN;
            int l2 = (mid2 > 0) ? arr2[mid2 - 1] : INT_MIN;
            int r1 = (mid1 < m) ? arr1[mid1] : INT_MAX;
            int r2 = (mid2 < n) ? arr2[mid2] : INT_MAX;
            
            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        
        return 0; 
    }
};


//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends
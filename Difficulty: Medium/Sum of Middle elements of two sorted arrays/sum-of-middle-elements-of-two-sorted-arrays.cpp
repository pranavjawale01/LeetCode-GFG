//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int n = arr1.size();
        int left = 0, right = n;

        while (left <= right) {
            int i1 = (left + right) / 2;
            int i2 = n - i1;

            int min1 = (i1 == n) ? INT_MAX : arr1[i1];
            int max1 = (i1 == 0) ? INT_MIN : arr1[i1 - 1];
            
            int min2 = (i2 == n) ? INT_MAX : arr2[i2];
            int max2 = (i2 == 0) ? INT_MIN : arr2[i2 - 1];

            if (max1 <= min2 && max2 <= min1) {
                return max(max1, max2) + min(min1, min2);
            } else if (max1 > min2) {
                right = i1 - 1;
            } else {
                left = i1 + 1;
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
// C++ Program to count pairs whose sum divisible
// by '4'
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int count4Divisibiles(vector<int>& arr) {
        // Complete the function
        vector<int> mod(4, 0);
        for (int x : arr) {
            mod[x % 4]++;
        }
        int ans = (mod[0] * (mod[0] - 1) / 2) + (mod[2] * (mod[2] - 1) / 2) + mod[1] * mod[3];
        return ans;
    }
};

//{ Driver Code Starts.
//   Driver code
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
        Solution ob;
        cout << ob.count4Divisibiles(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
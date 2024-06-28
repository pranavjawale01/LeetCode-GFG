//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool is_palin(string k){
        int n = k.size();
        for(int i = 0; i < (n/2); i++){
            if(k[i] != k[n-i-1]){
                return false;
            }
        }
        return true;
    }
    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n = arr.size();
        for(int i = 0; i < n; i++){
            string str;
            for(int j = 0; j < n; j++){
                str += to_string(arr[i][j]);
            }
            if(is_palin(str)){
                string ans;
                ans += to_string(i);
                ans += " R";
                return ans;
            }
        }
         for(int j = 0; j < n; j++){
            string str;
            for(int i = 0; i < n; i++){
                str+= to_string(arr[i][j]);
            }
            if(is_palin(str)){
                string ans;
                ans += to_string(j);
                ans += " C";
                return ans;
            }
        }
        return to_string(-1);
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countNumberswith4(int N) {
        // code here
        int num = 4, count = 0;
        while (num <= N) {
            int temp = num;
            while (temp > 0) {
                if (temp % 10 == 4) {
                    count++;
                    break;
                }
                temp /= 10;
            }
            num++;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends
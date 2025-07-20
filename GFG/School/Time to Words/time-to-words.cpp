//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string timeToWord(int H, int M){
        // code here
        string tick;
        string nums[] = {"twelve", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine"};
        string oclock = " o' clock";
        string to = " to ";
        string past = " past ";
        string qrtr = "quarter";
        string half = "half";
        string mints = " minutes";
        string mint = " minute";
        if(M == 0)
        {
            tick = nums[H] + oclock;
        }
        else if(M == 15) 
        {
            tick = qrtr + past + nums[H];
        }
        else if(M == 30)
        {
            tick = half + past + nums[H];
        }
        else if(M == 45) 
        {
            tick =  qrtr + to + nums[H+1];
        }
        else
        {
                if(M == 1)
                {
                    tick = nums[1] + mint + past + nums[H];
                }
                else if(M == 59) 
                {
                    tick = nums[1] + mint + to + nums[(H+1)%12];
                }
                else if(M<30) 
                {
                    tick = nums[M] + mints + past + nums[H];
                }
                else 
                {
                    tick = nums[60-M] + mints + to + nums[(H+1)%12];
                }
        }
        return tick;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  H, M;
        cin >> H >> M;
        Solution ob;
        cout<<ob.timeToWord(H,M)<<endl;
    }
    return 0;
}

// } Driver Code Ends
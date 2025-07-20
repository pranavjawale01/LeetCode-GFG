//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    unordered_map<char, int> charFreq;
        map<int, int> freqCount;
        for(const char &c : s) {
            charFreq[c]++;
        }
        for(const auto &p : charFreq) {
            freqCount[p.second]++;
        }
        if (freqCount.size() == 1) {
            return true;
        } else if (freqCount.size() == 2) {
            auto it = freqCount.begin();
            auto firstFreq = *it;
            it++;
            auto secondFreq = *it;
            if (firstFreq.first == 1 && firstFreq.second == 1){
                return true;
            }
            if ((secondFreq.first - firstFreq.first == 1) && secondFreq.second == 1) {
                return true;
            }
        }
        return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends
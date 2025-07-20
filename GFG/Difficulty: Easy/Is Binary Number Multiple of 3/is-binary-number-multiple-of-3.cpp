//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    int remainder = 0;
        int n = s.length();
        
        for (int i = n - 1; i >= 0; i--) {
            remainder = (remainder * 2 + (s[i] - '0')) % 3;
        }
        
        return (remainder == 0) ? 1 : 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends
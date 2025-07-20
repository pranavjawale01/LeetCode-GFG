//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}

// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
     //Your code here
     int n = s.length(), m = x.length();
     bool flag = true;
     for (int i = 0; i < n; i++) {
         flag = true;
         for (int j = 0; j < m; j++) {
             if (s[i+j] != x[j]) {
                 flag = false;
                 break;
             }
         }
         if (flag) {
             return i;
         }
     }
     return -1;
}
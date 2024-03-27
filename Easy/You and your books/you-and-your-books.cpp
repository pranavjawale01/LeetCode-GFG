//{ Driver Code Starts
#include <iostream>
#include<algorithm>
#include<cstdio>
//#include<Windows.h> 
using namespace std;  

// } Driver Code Ends

class Solution{
    public:
    /*You are requried to complete this method */
    int max_Books(int a[], int n, int k)
    {
        // Your code here
        int max_books = 0;
        int current_sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= k) {
                current_sum += a[i];
                max_books = max(max_books, current_sum);
            }
            else {
                current_sum = 0;
            }
        }
        return max_books;
    }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
  	int n,k;
  	cin>>n>>k;
  	int ar[n];
  	for(int i=0;i<n;i++)
  	{
  		cin>>ar[i];
  	}
  	Solution ob;
  	cout<<ob.max_Books(ar,n,k)<<endl;
        
  }    
  return 0;
}


// } Driver Code Ends
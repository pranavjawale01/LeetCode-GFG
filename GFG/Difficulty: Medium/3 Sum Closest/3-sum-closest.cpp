//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int A[], int N, int X)
    {
        // code here
        sort(A, A + N);
        int ans = 0, mindiff = INT_MAX;
        for (int i = 0; i < N - 2; i++) {
            int left = i + 1, right = N - 1;
            while (left < right) {
                int sum = A[i] + A[left] + A[right];
                int diff = abs(sum - X);
                if (diff < mindiff) {
                    mindiff = diff;
                    ans = sum;
                }
                if (sum < X) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
        //code here
        vector<int> freq(K, 0);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int rem = A[i] % K;
            if (rem < 0) rem += K;
            int com = (rem == 0) ? 0 : K - rem;
            ans += freq[com];
            freq[rem]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	
cout << "~" << "\n";
}


	return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int kadaneMax(int arr[], int n) {
        int currSum = arr[0];
        int maxSum = arr[0];
        for (int i = 1; i < n; i++) {
            currSum = max(currSum + arr[i], arr[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        int maxSum = kadaneMax(arr, num);
        int sum = 0;
        for (int i = 0; i < num; i++) {
            sum += arr[i];
            arr[i] = -arr[i];
        }
        int minSum = kadaneMax(arr, num);
        if (maxSum > 0) {
            return max(maxSum, sum + minSum);
        }
        return maxSum;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
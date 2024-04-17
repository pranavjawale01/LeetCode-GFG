//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int merge(int arr[], int low, int mid, int high) {
        int temp[high - low + 1];
        int k = 0;
        int i = low;
        int j = mid + 1;
        int inv = 0;
        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                inv += mid - i + 1;
                temp[k++] = arr[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        while (j <= high) {
            temp[k++] = arr[j++];
        }
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        return inv;
    }
    int mergeSort(int arr[], int i, int j) {
        if (i >= j) {
            return 0;
        }
        int inv = 0;
        int mid = i + (j - i) / 2;
        inv += mergeSort(arr, i, mid);
        inv += mergeSort(arr, mid + 1, j);
        inv += merge(arr, i, mid, j);
        return inv;
    }
    int inversionCount(int arr[] , int n) {
        return mergeSort(arr, 0, n - 1);
    }
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here   
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] * i;
        }
        return inversionCount(arr, n);
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends
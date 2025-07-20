//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int binarySearch(vector<int> &arr, int mid) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int midIdx = low + (high - low) / 2;
            if (arr[midIdx] <= mid) {
                low = midIdx + 1;
            } else {
                high = midIdx - 1;
            }
        }
        return low;
    }
    
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here          
        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int i = 0; i < R; i++) {
            minVal = min(minVal, matrix[i][0]);
            maxVal = max(maxVal, matrix[i][C-1]);
        }
        int req = (R * C) / 2;
        while (minVal < maxVal) {
            int mid = minVal + (maxVal - minVal) / 2;
            int count = 0;
            for (int i = 0; i < R; i++) {
                count += binarySearch(matrix[i], mid);
            }
            if (count <= req) {
                minVal = mid + 1;
            } else {
                maxVal = mid;
            }
        }
        return minVal;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here
        int minVal = matrix[0][0];
        int maxVal = matrix[0][C-1];
        
        for(int i = 1; i < R; i++){
            minVal = min(minVal, matrix[i][0]);
            maxVal = max(maxVal, matrix[i][C-1]);
        }
        
        int desiredCount = (R * C + 1) / 2;
        
        while(minVal < maxVal){
            int mid = minVal + (maxVal - minVal) / 2;
            
            int count = 0;
            for(int i = 0; i < R; i++){
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            
            if(count < desiredCount) {
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
    }
    return 0;
}
// } Driver Code Ends
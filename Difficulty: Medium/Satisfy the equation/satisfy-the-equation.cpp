//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
        // code here
        unordered_map<int, vector<pair<int, int>>> sumMap;
        vector<int> result = {-1, -1, -1, -1};
        
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int sum = A[i] + A[j];
                
                if (sumMap.find(sum) != sumMap.end()) {
                    for (auto& p : sumMap[sum]) {
                        int k = p.first;
                        int l = p.second;
                        if (i != k && i != l && j != k && j != l) {
                            vector<int> candidate = {k, l, i, j};
                            if (result == vector<int>{-1, -1, -1, -1} || candidate < result) {
                                result = candidate;
                            }
                        }
                    }
                }
                sumMap[sum].push_back({i, j});
            }
        }
        
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
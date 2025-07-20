class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int len = original.size();
        
        if (len != m * n) {
            return {};
        }
        
        vector<vector<int>> ans(m, vector<int>(n));
        
        for (int i = 0; i < len; ++i) {
            ans[i / n][i % n] = original[i];
        }
        
        return ans;
    }
};
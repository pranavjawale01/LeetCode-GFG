class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>> mp;
        vector<int> ans;
        int n = mat[0].size(), m = mat.size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i+j].push_back(mat[i][j]);
            }
        }
        bool flag = true;
        for (auto &it : mp) {
            if (flag) {
                reverse(begin(it.second), end(it.second));
            }
            for (int &num : it.second) {
                ans.push_back(num);
            }
            flag = !flag;
        }
        return ans;
    }
};
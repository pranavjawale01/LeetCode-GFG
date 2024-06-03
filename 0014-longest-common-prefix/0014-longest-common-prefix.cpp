class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs[0].size();
        if (strs[0][0] != strs[strs.size() - 1][0]) {
            return "";
        }
        for (int i = 0; i < n; i++) {
            if (strs[0][i] != strs[strs.size() - 1][i]) {
                return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};
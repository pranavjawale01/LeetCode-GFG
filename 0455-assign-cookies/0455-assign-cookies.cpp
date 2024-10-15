class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // if (g.empty() || s.empty()) {
        //     return 0;
        // }
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int i = 0 , j = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                count++;
                i++;
            }
            j++;
        }
        return count;
    }
};
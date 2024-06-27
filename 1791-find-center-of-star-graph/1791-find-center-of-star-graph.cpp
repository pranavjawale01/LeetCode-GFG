class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, int> mp;
        for (auto edge : edges) {
            mp[edge[0]]++;
            mp[edge[1]]++;
        }
        for (auto x : mp) {
            if (x.second == n) {
                return x.first;
            }
        }
        return -1;
    }
};
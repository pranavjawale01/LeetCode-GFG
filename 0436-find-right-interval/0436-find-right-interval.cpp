class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans;
        map<int, int> mp{{INT_MAX, -1}};
        for (int i = 0; i < intervals.size(); i++) {
            mp[intervals[i][0]] = i;
        }
        for (int i = 0; i < intervals.size(); i++) {
            int end = intervals[i][1];
            auto it = mp.lower_bound(end);
            ans.push_back(it->second);
        }
        return ans;
    }
};
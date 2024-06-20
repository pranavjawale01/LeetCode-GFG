class Solution {
public:
    int binarySearch(vector<pair<int, int>> &vec, int end) {
        int low = 0, high = vec.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vec[mid].first >= end) {
                ans = vec[mid].second;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({intervals[i][0], i});
        }
        sort(vec.begin(), vec.end());
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            ans[i] = binarySearch(vec, end);
        }
        return ans;
    }
};



// class Solution {
// public:
//     vector<int> findRightInterval(vector<vector<int>>& intervals) {
//         vector<int> ans;
//         map<int, int> mp{{INT_MAX, -1}};
//         for (int i = 0; i < intervals.size(); i++) {
//             mp[intervals[i][0]] = i;
//         }
//         for (int i = 0; i < intervals.size(); i++) {
//             int end = intervals[i][1];
//             auto it = mp.lower_bound(end);
//             ans.push_back(it->second);
//         }
//         return ans;
//     }
// };
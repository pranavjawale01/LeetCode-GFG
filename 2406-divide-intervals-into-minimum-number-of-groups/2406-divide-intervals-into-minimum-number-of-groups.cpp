class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        unordered_map<int, int> mp;
        for (auto &x : intervals) {
            mp[x[0]]++;
            mp[x[1] + 1]--;
        }
        int maxGrp = 0;
        int curGrp = 0;
        for (auto x : mp) {
            curGrp += x.second;
            maxGrp = max(maxGrp, curGrp);
        }
        return maxGrp;
    }
};








// TLE
// class Solution {
// public:
//     int minGroups(vector<vector<int>>& intervals) {
//         sort(intervals.begin(), intervals.end());
//         unordered_map<int, vector<pair<int, int>>> mp;

//         for (auto& x : intervals) {
//             int a = x[0], b = x[1];
//             int grp = 1;

//             while (true) {
//                 if (mp[grp].empty() || mp[grp].back().second < a) {
//                     mp[grp].push_back({a, b});
//                     break;
//                 }
//                 grp++;
//             }
//         }
        
//         return mp.size();
//     }
// };
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a = edges[0][0];
        int b = edges[0][1];
        if (a == edges[1][0] || a == edges[1][1]) {
            return a;
        }
        return b;
    }
};




// class Solution {
// public:
//     int findCenter(vector<vector<int>>& edges) {
//         int n = edges.size();
//         unordered_map<int, int> mp;
//         for (auto edge : edges) {
//             mp[edge[0]]++;
//             mp[edge[1]]++;
//         }
//         for (auto x : mp) {
//             if (x.second == n) {
//                 return x.first;
//             }
//         }
//         return -1;
//     }
// };
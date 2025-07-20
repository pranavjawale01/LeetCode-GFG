class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n+1, 0);
        for (vector<int>& vec : trust) {
            int i = vec[0];
            int o = vec[1];
            count[i]--;
            count[o]++;
        }
        for (int i = 1; i <= n; i++) {
            if (count[i] == n-1) {
                return i;
            }
        }
        return -1;
    }
};

// class Solution {
// public:
//     int findJudge(int n, vector<vector<int>>& trust) {
//         vector<int> indegree(n+1, 0), outdegree(n+1, 0);
//         for (vector<int>& vec : trust) {
//             int u = vec[0];
//             int v = vec[1];
//             outdegree[u]++;
//             indegree[v]++;
//         }
//         for (int i = 1; i <= n; i++) {
//             if (indegree[i] == n-1 && outdegree[i] == 0) {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };
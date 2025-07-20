class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> connected(n, vector<bool>(n, false));
        vector<int> count(n, 0);

        for (const auto& road : roads) {
            count[road[0]]++;
            count[road[1]]++;
            connected[road[0]][road[1]] = true;
            connected[road[1]][road[0]] = true;
        }

        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = count[i] + count[j] - (connected[i][j] ? 1 : 0);
                res = max(res, rank);
            }
        }

        return res;
    }
};
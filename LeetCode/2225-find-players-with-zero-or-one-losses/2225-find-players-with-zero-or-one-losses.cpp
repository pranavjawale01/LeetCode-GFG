class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lost_map;
        for (int i = 0; i < matches.size(); i++) {
            lost_map[matches[i][1]]++;
        }
        vector<int> win, loss;
        for (int i = 0; i < matches.size(); i++) {
            if (lost_map.find(matches[i][0]) == lost_map.end()) {
                win.push_back(matches[i][0]);
                lost_map[matches[i][0]] = 2;
            }
            if (lost_map[matches[i][1]] == 1) {
                loss.push_back(matches[i][1]);
            }
        }
        sort(win.begin(), win.end());
        sort(loss.begin(), loss.end());
        return {win, loss};
    }
};
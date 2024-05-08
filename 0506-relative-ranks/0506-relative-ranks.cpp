class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[score[i]] = i;
        }
        sort(score.begin(), score.end(), greater<int>());
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                int ath = mp[score[i]];
                ans[ath] = "Gold Medal";
            } else if (i == 1) {
                int ath = mp[score[i]];
                ans[ath] = "Silver Medal";
            } else if(i == 2) {
                int ath = mp[score[i]];
                ans[ath] = "Bronze Medal";
            } else {
                int ath = mp[score[i]];
                ans[ath] = to_string(i+1);
            }
        }
        return ans;
    }
};
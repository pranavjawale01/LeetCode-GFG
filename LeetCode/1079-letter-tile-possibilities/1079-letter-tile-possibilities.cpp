class Solution {
public:
    int numTilePossibilities(string tiles) {
        int ans = 0;
        vector<int> count(26, 0);
        for (char c : tiles) {
            count[c - 'A']++;
        }
        function<void()> solve = [&]() {
            ans++;
            for (int i = 0; i < 26; i++) {
                if (count[i] == 0) continue;
                count[i]--;
                solve();
                count[i]++;
            }
        };
        solve();
        return ans - 1;
    }
};
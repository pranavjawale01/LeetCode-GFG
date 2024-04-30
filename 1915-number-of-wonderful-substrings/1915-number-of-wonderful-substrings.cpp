class Solution {
public:
    int wonderfulSubstrings(string word) {
        int n = word.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> count(10, 0);
            for (int j = i; j < n; j++) {
                count[word[j] - 'a']++;
                if (isWonderful(count)) {
                    ans++;
                }
            }
        }
        return ans;
    }

    bool isWonderful(vector<int> &count) {
        int oddCount = 0;
        for (int i = 0; i < 10; i++) {
            if (count[i] % 2 != 0) {
                oddCount++;
            }
        }
        return oddCount <= 1;
    }
};
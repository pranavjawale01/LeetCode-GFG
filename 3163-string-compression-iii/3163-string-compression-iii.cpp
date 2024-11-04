class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int count = 1;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (i + 1 < word.size() && word[i] == word[i + 1] && count < 9) {
                count++;
            } else {
                ans += to_string(count) + word[i];
                count = 1;
            }
        }
        return ans;
    }
};
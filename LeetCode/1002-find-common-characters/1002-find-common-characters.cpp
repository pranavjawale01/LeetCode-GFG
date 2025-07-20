class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<int> count(26, INT_MAX);

        for (int i = 0; i < n; i++) {
            vector<int> temp(26, 0);
            for (char c : words[i]) {
                temp[c - 'a']++;
            }
            for (int j = 0; j < 26; j++) {
                count[j] = min(temp[j], count[j]);
            }
        }

        vector<string> ans;
        for (int i = 0; i < 26; i++) {
            while (count[i] > 0) {
                ans.push_back(string(1, 'a' + i));
                count[i]--;
            }
        }
        return ans;
    }
};
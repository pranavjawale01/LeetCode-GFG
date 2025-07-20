class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26, 0);
        for (string x : words2) {
            vector<int> temp(26, 0);
            for (char c : x) temp[c - 'a']++;
            for (int i = 0; i < 26; i++) freq[i] = max(freq[i], temp[i]);
        }
        vector<string> ans;
        for (string x : words1) {
            vector<int> temp(26, 0);
            for (char c : x) temp[c - 'a']++;
            bool flag = true;
            for (int i = 0; i < 26; i++) if (freq[i] > temp[i]) flag = false;
            if (flag) ans.push_back(x);
        }
        return ans;
    }
};
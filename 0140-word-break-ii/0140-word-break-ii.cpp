class Solution {
public:
    vector<string> result;
    unordered_set<string> dict;

    void solve(int i, string &curr, string &s) {
        if (i >= s.length()) {
            result.push_back(curr);
            return;
        }
        for (int j = i; j < s.length(); j++) {
            string tempWord = s.substr(i, j - i + 1);
            if (dict.find(tempWord) != dict.end()) {
                string origSentence = curr;
                if (!curr.empty()) {
                    curr += " ";
                }
                curr += tempWord;
                solve(j+1, curr, s);
                curr = origSentence;
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string &word : wordDict) {
            dict.insert(word);
        }
        string curr = "";
        solve(0, curr, s);
        return result;
    }
};
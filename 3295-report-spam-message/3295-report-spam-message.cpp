class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> st(bannedWords.begin(), bannedWords.end());
        int count = 0;
        for (string &x : message) {
            if (st.find(x) != st.end()) {
                count++;
            }
        }
        return count >= 2;
    }
};
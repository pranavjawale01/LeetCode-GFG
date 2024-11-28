class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.length(), i = 0;
        while (i < n && s[i] == ' ') i++;
        string ans = "";
        string temp = "";
        for (; i < n; i++) {
            if (s[i] == ' ') {
                if (!temp.empty()) {
                    ans += temp + " ";
                    temp = "";
                }
            } else {
                temp = s[i] + temp;
            }
        }
        if (!temp.empty()) {
            ans += temp;
        } else if (!ans.empty()) {
            ans.pop_back();
        }
        return ans;
    }
};
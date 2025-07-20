class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int m = s.length();
        int n = spaces.size();
        string ans = "";
        int j = 0;
        for (int i = 0; i < m; i++) {
            if (j < n && i == spaces[j]) {
                ans += " ";
                j++;
            }
            ans += s[i];
        }
        return ans;
    }
};
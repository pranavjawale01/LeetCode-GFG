class Solution {
public:
    string solve(string &s) {
        string temp = "";
        for (char c : s) {
            temp += c + 1;
        }
        return s + temp;
    }
    char kthCharacter(int k) {
        string s = "a";
        while (s.size() < k) {
            s = solve(s);
        }
        return s[k-1];
    }
};
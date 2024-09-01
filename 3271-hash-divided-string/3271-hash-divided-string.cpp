class Solution {
public:
    string stringHash(string s, int k) {
        string ans = "";
        int n = s.length();
        for (int i = 0; i < n; i += k) {
            int sum = 0;
            for (int j = i; j < i + k; j++) {
                sum += (s[j] - 'a');
            }
            sum %= 26;
            ans.push_back(sum + 'a');
        }
        return ans;
    }
};
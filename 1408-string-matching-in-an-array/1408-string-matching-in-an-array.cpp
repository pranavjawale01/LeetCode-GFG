class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (string x : words) {
            for (string y : words) {
                if (x == y) continue;
                if (y.find(x) != string::npos) {
                    ans.push_back(x);
                    break;
                }
            }
        }
        return ans;
    }
};
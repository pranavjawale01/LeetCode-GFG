class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        int n = target.size();
        string temp = "";
        for (int i = 0; i < n; i++) {
            temp += 'a';
            ans.push_back(temp);
            while (temp.back() != target[i]) {
                temp.back() += 1;
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
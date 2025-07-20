class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> mp;
        istringstream iss1(s1);
        string word;
        
        while (iss1 >> word) {
            mp[word]++;
        }

        istringstream iss2(s2);
        
        while (iss2 >> word) {
            mp[word]++;
        }

        vector<string> ans;
        for (const auto& x : mp) {
            if (x.second == 1) {
                ans.push_back(x.first);
            }
        }

        return ans;
    }
};
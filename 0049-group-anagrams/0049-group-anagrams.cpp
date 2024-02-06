class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> output;
        for (string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }
        for (const auto& entry : mp) {
            output.push_back(entry.second);
        }
        return output;
    }
};
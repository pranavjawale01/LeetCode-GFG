class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;

        for (const string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            anagramMap[key].push_back(str);
        }

        vector<vector<string>> result;
        for (const auto& entry : anagramMap) {
            result.push_back(entry.second);
        }

        return result;
    }
};
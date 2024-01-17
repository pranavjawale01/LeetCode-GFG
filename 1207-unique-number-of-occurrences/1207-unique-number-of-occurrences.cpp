class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> unique;        
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }
        for (auto it : mp) {
            if (!unique.insert(it.second).second) {
                return false;
            }
        }
        return true;
    }
};
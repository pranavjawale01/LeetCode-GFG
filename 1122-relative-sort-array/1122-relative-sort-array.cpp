class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        for (int x : arr1) {
            mp[x]++;
        }
        vector<int> ans;
        for (int x : arr2) {
            while (mp[x] > 0) {
                ans.push_back(x);
                mp[x]--;
            }
            mp.erase(x);
        }
        for (auto& [key, value] : mp) {
            while (value > 0) {
                ans.push_back(key);
                value--;
            }
        }
        
        return ans;
    }
};
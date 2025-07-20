class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int, int> mp;
        for (int x : target) {
            mp[x]++;
        }
        for (int x : arr) {
            if (mp.find(x) == mp.end()) {
                return false;
            }
            mp[x]--;
            if (mp[x] == 0) {
                mp.erase(x);
            }
        }
        return mp.size() == 0;
    }
};





// class Solution {
// public:
//     bool canBeEqual(vector<int>& target, vector<int>& arr) {
//         sort(target.begin(), target.end());
//         sort(arr.begin(), arr.end());
//         return arr == target ? true : false;
//     }
// };
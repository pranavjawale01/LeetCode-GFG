class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        int rank = 1;
        for (int x : st) {
            mp[x] = rank;
            rank++;
        }
        for (int &x : arr) {
            x = mp[x];
        }
        return arr;
    }
};
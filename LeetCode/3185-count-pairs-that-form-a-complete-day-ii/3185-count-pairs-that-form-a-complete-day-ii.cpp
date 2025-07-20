class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long count = 0;
        unordered_map<int, int> mp;
        for (int hour : hours) {
            int rem = hour % 24;
            int com = (24 - rem) % 24;
            if (mp.find(com) != mp.end()) {
                count += mp[com];
            }
            mp[rem]++;
        }
        return count;
    }
};
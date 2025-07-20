class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> mp;
        int count = 0;
        for (int hour : hours) {
            int mod = hour % 24;
            int com = (24 - mod) % 24;
            if (mp.find(com) != mp.end()) {
                count += mp[com];
            }
            mp[mod]++;
        }
        return count;
    }
};



// class Solution {
// public:
//     int countCompleteDayPairs(vector<int>& hours) {
//         int n = hours.size();
//         int count = 0;
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if ((hours[i] + hours[j]) % 24 == 0) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };
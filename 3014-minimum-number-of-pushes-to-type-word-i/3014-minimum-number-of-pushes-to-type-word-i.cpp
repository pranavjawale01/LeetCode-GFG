class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += ((i / 8) + 1) * freq[i];
        }
        return ans;
    }
};






// class Solution {
// public:
//     int minimumPushes(string word) {
//         unordered_map<int, int> mp;
//         int key = 2;
//         int ans = 0;
//         for (char c : word) {
//             if (key > 9) {
//                 key = 2;
//             }
//             mp[key]++;
//             ans += mp[key];
//             key++;
//         }
//         return ans;
//     }
// };






// class Solution {
// public:
//     int minimumPushes(string word) {
//         unordered_map<char, int> mp;
//         for (char c : word) {
//             mp[c]++;
//         }
//         if (mp.size() <= 8) {
//             return word.size();
//         }
//         if (mp.size() > 8 && mp.size() < 17) {
//             return 8 + (mp.size() - 8) * 2;
//         }
//         if (mp.size() > 16 && mp.size() < 25) {
//             return 8 + 16 + (mp.size() - 16) * 3;
//         }
//         return 8 + 16 + 24 + (mp.size() - 24) * 4;
//     }
// };
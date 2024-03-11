class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> mp(26, -1);
        for (int i = 0; i < order.length(); i++) {
            char ch = order[i];
            mp[ch - 'a'] = i;
        }
        auto myComparator = [&mp](char& ch1, char& ch2) {
            return mp[ch1 - 'a'] < mp[ch2 - 'a'];
        };
        sort(begin(s), end(s), myComparator);
        return s;
    }
};
// class Solution {
// public:
//     string customSortString(string order, string s) {
//         unordered_map<char, int> mp;
//         for (char ch : s) {
//             mp[ch]++;
//         }
//         string ans = "";
//         for (char ch : order) {
//             if (mp[ch] > 0) {
//                 while (mp[ch] != 0) {
//                     ans += ch;
//                     mp[ch]--;
//                 }
//             }
//         }
//         for (auto x : mp) {
//             if (x.second > 0) {
//                 while (x.second != 0) {
//                     ans += x.first;
//                     x.second--;
//                 }
//             }
//         }
//         return ans;
//     }
// };
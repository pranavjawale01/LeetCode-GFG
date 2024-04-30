class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int> prefixCount(1024, 0);
        int prefix = 0, n = word.size();
        long long result = 0;
        prefixCount[0] = 1;
        for (int i = 0; i < n; i++) {
            int c = word[i] - 'a';
            prefix ^= (1 << c);
            result += prefixCount[prefix];
            prefixCount[prefix]++;
            for (int bit = 0; bit < 10; bit++) {
                int diff = (1 << bit) ^ prefix;
                result += prefixCount[diff];
            }
        }
        return result;
    }
};



// class Solution {
// public:
//     int wonderfulSubstrings(string word) {
//         int n = word.size();
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             vector<int> count(10, 0);
//             for (int j = i; j < n; j++) {
//                 count[word[j] - 'a']++;
//                 if (isWonderful(count)) {
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }

//     bool isWonderful(vector<int> &count) {
//         int oddCount = 0;
//         for (int i = 0; i < 10; i++) {
//             if (count[i] % 2 != 0) {
//                 oddCount++;
//             }
//         }
//         return oddCount <= 1;
//     }
// };
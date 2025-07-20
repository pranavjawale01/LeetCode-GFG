class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int result = 0;
        int oddFreq = 0;
        for (char ch : s) {
            mp[ch]++;
            if (mp[ch] % 2 != 0) {
                oddFreq++;
            } else {
                oddFreq--;
            }
        }
        if (oddFreq > 0) {
            return n - oddFreq + 1;
        }
        return n;
    }
};



// class Solution {
// public:
//     int longestPalindrome(string s) {
//         int n = s.length();
//         unordered_map<char, int> mp;
//         for (char c : s) {
//             mp[c]++;
//         }
//         int result = 0;
//         bool oddFreq = false;
//         for (auto &it : mp) {
//             if (it.second % 2 == 0) {
//                 result += it.second;
//             } else {
//                 result += it.second - 1;
//                 oddFreq = true;
//             }
//         }
//         if (oddFreq) {
//             result++;
//         }
//         return result;
//     }
// };



// class Solution {
// public:
//     int longestPalindrome(string s) {
//         int n = s.length();
//         unordered_set<char> st;
//         int result = 0;
//         for (char c : s) {
//             if (st.count(c)) {
//                 result += 2;
//                 st.erase(c);
//             } else {
//                 st.insert(c);
//             }
//         }
//         if (!st.empty()) {
//             result++;
//         }
//         return result;
//     }
// };
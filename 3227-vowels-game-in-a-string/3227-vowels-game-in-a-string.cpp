class Solution {
public:
    bool doesAliceWin(string s) {
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                return true;
            }
        }
        return false;
    }
};





// class Solution {
// public:
//     bool doesAliceWin(string s) {
//         map<int, int> mp;
//         for (char c : s) {
//             if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
//                 mp[c]++;
//             }
//         }
//         int sum = 0;
//         for (auto x : mp) {
//             sum += x.second;
//             if (sum > 0) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };




// class Solution {
// public:
//     bool doesAliceWin(string s) {
//         int count = 0;
//         int n = s.length();
//         for (char c : s) {
//             if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
//                 count++;
//             }
//         }
//         if (count == 0) {
//             return false;
//         }
//         return true;
//     }
// };
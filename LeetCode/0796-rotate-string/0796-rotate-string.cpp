class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.size(), n = goal.size();
        if (m == n && (s + s).find(goal) != string::npos) {
            return true;
        }
        return false;
    }
};






// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         int m = s.size(), n = goal.size();
//         if (m != n) {
//             return false;
//         }
//         for (int i = 1; i <= m; i++) {
//             rotate(s.begin(), s.begin() + 1, s.end());
//             if (s == goal) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };
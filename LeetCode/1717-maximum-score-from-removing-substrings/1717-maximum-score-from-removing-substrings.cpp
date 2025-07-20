class Solution {
public:
    int solve(string &s, string target, int point) {
        int totalPoints = 0;
        int n = s.length();
        int writeidx = 0;
        for (int readidx = 0; readidx < n; readidx++) {
            s[writeidx++] = s[readidx];
            if (writeidx > 1 && s[writeidx-1] == target[1] && s[writeidx-2] == target[0]) {
                writeidx -= 2;
                totalPoints += point;
            }
        }
        s = s.substr(0, writeidx);
        return totalPoints;
    }
    int maximumGain(string s, int x, int y) {
        string s1 = "ab", s2 = "ba";
        if (y > x) {
            swap(x, y);
            swap(s1, s2);
        }
        return solve(s, s1, x) + solve(s, s2, y);
    }
};





// class Solution {
// public:
//     int solve(string &s, string targetStr, int point) {
//         int totalPoints = 0, n = s.length();
//         stack<char> st;
//         for (int i = 0; i < n; i++) {
//             if (st.empty()) {
//                 st.push(s[i]);
//             } else {
//                 if (s[i] == targetStr[1] && st.top() == targetStr[0]) {
//                     st.pop();
//                     totalPoints += point;
//                 } else {
//                     st.push(s[i]);
//                 }
//             }
//         }
//         s = "";
//         while (!st.empty()) {
//             s += st.top();
//             st.pop();
//         }
//         reverse(s.begin(), s.end());
//         return totalPoints;
//     }
//     int maximumGain(string s, int x, int y) {
//         string s1 = "ab" , s2 = "ba";
//         if (x < y) {
//             swap(s1, s2);
//             swap(x, y);
//         }
//         return solve(s, s1, x) + solve(s, s2, y);
//     }
// };
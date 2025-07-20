class Solution {
public:
    string answerString(string word, int numFriends) {
        string ans = ""; 
        char maxc = *max_element(word.begin(), word.end());
        int n = word.size(); 
        if (numFriends == 1) return word;     
        for(int i = 0; i < n; i++) { 
            if (word[i] == maxc) { 
                int len = min(n - i, n - numFriends + 1); 
                if (len <= 0) continue; 
                string temp = word.substr(i, len); 
                if (temp > ans) ans = temp; 
            } 
        } 
        return ans; 
    }
};




// TLE
// class Solution {
// public:
//     string answerString(string word, int numFriends) {
//         string ans = "";
//         int n = word.size();
//         function<void(int, int)> solve = [&](int i, int rem) {
//             if (i == n) return;
//             if (rem == 0) {
//                 // if (i == n) {
//                 //     ans = max(ans, curr);
//                 // }
//                 return;
//             }
//             for (int l = 1; l <= n - i - (rem - 1); l++) {
//                 string part = word.substr(i, l);
//                 ans = max(ans, part);
//                 solve(i + l, rem - 1);
//             }
//         };
//         solve(0, numFriends);
//         return ans;
//     }
// };
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string word : words) {
            int n = word.size();
            if (equal(word.begin(), word.begin() + n/2, word.rbegin())) {
                return word;
            }
        }
        return "";
    }
};

// class Solution {
// public:
//     bool isPalli(string word) {
//         string newWord = word;
//         reverse(newWord.begin(), newWord.end());
//         return word == newWord;
//     }

//     string firstPalindrome(vector<string>& words) {
//         for (string word : words) {
//             if (isPalli(word)) {
//                 return word;
//             }
//         }
//         return "";
//     }
// };
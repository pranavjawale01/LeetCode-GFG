class Solution {
public:
    bool isPalli(string word) {
        string newWord = word;
        reverse(newWord.begin(), newWord.end());
        return word == newWord;
    }

    string firstPalindrome(vector<string>& words) {
        for (string word : words) {
            if (isPalli(word)) {
                return word;
            }
        }
        return "";
    }
};
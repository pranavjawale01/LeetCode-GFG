class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (word[i] == ch) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return word;
        }
        for (int i = 0; i <= index / 2; i++) {
            swap(word[i], word[index-i]);
        }
        return word;
    }
};
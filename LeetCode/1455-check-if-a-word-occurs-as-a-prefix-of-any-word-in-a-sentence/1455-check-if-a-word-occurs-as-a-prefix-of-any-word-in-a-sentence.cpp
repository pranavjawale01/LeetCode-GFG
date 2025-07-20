class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        int i = 1;
        string word;
        while (ss >> word) {
            if (word.size() >= searchWord.size()) {
                if (word.substr(0, searchWord.size()) == searchWord) {
                    return i;
                }
            }
            i++;
        }
        return -1;
    }
};
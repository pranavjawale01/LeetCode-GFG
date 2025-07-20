class Solution {
public:
    unordered_map<char, int> findCharCount(string chars) {
        unordered_map<char, int> charCount;
        for (char ch : chars) {
            charCount[ch]++;
        }
        return charCount;
    }

    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> charCount = findCharCount(chars);
        int count = 0;

        for (string word : words) {
            unordered_map<char, int> wordCharCount = findCharCount(word);
            bool check = true;
            for (char ch : word) {
                if (wordCharCount[ch] > charCount[ch]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                count += word.length();
            }
        }
        return count;
    }
};
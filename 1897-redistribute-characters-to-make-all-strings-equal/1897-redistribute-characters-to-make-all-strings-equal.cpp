class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> charCount;

        for (const string& word : words) {
            for (char c : word) {
                charCount[c]++;
            }
        }

        int numWords = words.size();
        for (const auto& entry : charCount) {
            if (entry.second % numWords != 0) {
                return false;
            }
        }
        return true;
    }
};
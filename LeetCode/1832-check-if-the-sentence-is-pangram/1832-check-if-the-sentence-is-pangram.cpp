class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> count(26, 0);
        for (char c : sentence) {
            count[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0) {
                return false;
            }
        }
        return true;
    }
};
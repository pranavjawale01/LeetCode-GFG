class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        int count = 0;
        int mid = s.length() / 2;
        for (int i = 0; i < mid; i++) {
            char A = s[i];
            char B = s[mid + i];
            if (vowels.count(A)) {
                count++;
            }
            if (vowels.count(B)) {
                count--;
            }
        }
        return count == 0;
    }
};
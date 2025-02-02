class Solution {
public:
    int maxDifference(string s) {
        int evenMin = INT_MAX;
        int oddMax = 0;
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        int n = s.size();
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            if (freq[i] % 2 == 0) {
                evenMin = min(evenMin, freq[i]);
            } else {
                oddMax = max(oddMax, freq[i]);
            }
        }
        return oddMax - evenMin;
    }
};
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        int length1 = s.length(), length2 = t.length();
        int len = INT_MAX, count = length2;
        string result = "";
        unordered_map<char, int> tMap;

        for (int i = 0; i < length2; i++) {
            tMap[t[i]]++;
        }

        int left = 0, right = 0;
        int minLeft = 0;

        while (right < length1) {
            if (tMap[s[right]] > 0) {
                count--;
            }
            tMap[s[right]]--;
            right++;

            while (count == 0) {
                if (right - left < len) {
                    len = right - left;
                    minLeft = left;
                }

                tMap[s[left]]++;
                if (tMap[s[left]] > 0) {
                    count++;
                }
                left++;
            }
        }

        if (len == INT_MAX) {
            return "";
        }

        return s.substr(minLeft, len);
    }
};
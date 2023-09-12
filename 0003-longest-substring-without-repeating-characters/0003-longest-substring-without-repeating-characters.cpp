class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        int left = 0;

        unordered_map<char, int> charIndex; 

        for (int right = 0; right < n; ++right) 
        {
            char currentChar = s[right];
            if (charIndex.find(currentChar) != charIndex.end()) 
            {
                left = max(left, charIndex[currentChar] + 1);
            }
            charIndex[currentChar] = right;
            int currentLength = right - left + 1;

            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
    }
};
/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, len = 0;
        string myString = "";

        while (i < s.length()) 
        {
            if (myString.find(s[i]) == string::npos) 
            {
                myString.push_back(s[i]);
                i++;
            }
            else 
            {
                len = max(len, static_cast<int>(myString.length()));
                myString.clear();
            }
        }

        len = max(len, static_cast<int>(myString.length()));

        return len;
    }
};
*/
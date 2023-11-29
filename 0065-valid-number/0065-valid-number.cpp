class Solution {
public:
    bool isNumber(string s) {
        bool result = false, dFlag = false, eFlag = false;
        int i = 0;
        
        if (s[i] == '-' || s[i] == '+') {
            i++;
        }

        while (isdigit(s[i])) {
            result = true;
            i++;
        }

        if (s[i] == '.') {
            i++;
            dFlag = true;
        }

        while (isdigit(s[i])) {
            result = true;
            i++;
        }

        if ((s[i] == 'e' || s[i] == 'E') && result && !eFlag) {
            i++;
            eFlag = true;
            result = false;
            if (s[i] == '-' || s[i] == '+') {
                i++;
            }
        }

        while (isdigit(s[i])) {
            result = true;
            i++;
        }

        while (isspace(s[i])) {
            i++;
        }

        return result && (s[i] == '\0');
    }
};
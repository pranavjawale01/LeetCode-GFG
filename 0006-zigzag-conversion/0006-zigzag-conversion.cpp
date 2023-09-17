class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        int len = s.length();
        string result;
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j + i < len; j += cycleLen) {
                result += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < len) {
                    result += s[j + cycleLen - i];
                }
            }
        }

        return result;
    }
};

/*
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        int len = s.length();
        int numCols = (len / numRows) + max(0, (numRows - 2)) * (len / numRows);
        char arr[numRows][numCols];

        int i = 0, j = 0, k = 0;

        while (k < len) {
            if (i == 0 || i == numRows - 1) {
                for (int row = 0; row < numRows && k < len; ++row) {
                    arr[row][j] = s[k++];
                }
                ++j;
            } else {
                arr[i][j] = s[k++];
                ++j;
                --i;
            }
        }

        string v = "";

        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                if (arr[row][col] != '\0') {
                    v += arr[row][col];
                }
            }
        }
        return v;
    }
};
*/
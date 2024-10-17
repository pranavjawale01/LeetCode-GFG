class Solution {
public:
    int maximumSwap(int num) {
        int len = log10(num) + 1;
        string s = to_string(num);
        vector<int> maxRight(len);
        maxRight[len - 1] = len - 1;
        for (int i = len - 2; i >= 0; i--) {
            int rightMaxIdx = maxRight[i+1];
            int rightMaxElement = s[rightMaxIdx];
            maxRight[i] = (s[i] > rightMaxElement) ? i : rightMaxIdx;
        }
        for (int i = 0; i < len; i++) {
            int maxRightIdx = maxRight[i];
            int maxRightElement = s[maxRightIdx];
            if (s[i] < maxRightElement) {
                swap(s[i], s[maxRightIdx]);
                return stoi(s);
            }
        }
        return num;
    }
};
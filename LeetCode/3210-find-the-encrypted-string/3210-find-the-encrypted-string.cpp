class Solution {
public:
    void rev(string &s, int i, int j) {
        while (i <= j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    string getEncryptedString(string s, int k) {
        int n = s.length();
        k = k % n;
        rev(s, 0, k-1);
        rev(s, k, n-1);
        rev(s, 0, n-1);
        return s;
    }
};
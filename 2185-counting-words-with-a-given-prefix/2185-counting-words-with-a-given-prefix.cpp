class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.size();
        int count = 0;
        for (string x : words) {
            if (x.substr(0, n) == pref) count++;
        }
        return count;
    }
};
class Solution {
public:
    bool check(int x, int y) {
        string s1 = to_string(x);
        string s2 = to_string(y);
        int n = s1.length(), m = s2.length();
        int maxlen = max(n, m);
        while (n != maxlen) {
            s1 = '0' + s1;
            n++;
        }
        while (m != maxlen) {
            s2 = '0' + s2;
            m++;
        }
        int diff = 0;
        unordered_map<char, int> mp1, mp2;
        for (int i = 0; i < n; i++) {
            diff += (s1[i] != s2[i]);
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        return diff <= 2 && mp1 == mp2;
    }
    int countPairs(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                } else if (check(nums[i], nums[j])) {
                    count++;
                }
            }
        }
        return count;
    }
};
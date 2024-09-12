class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> st(allowed.begin(), allowed.end());
        int count = 0;
        for (auto word : words) {
            bool flag = false;
            for (auto c : word) {
                if (st.find(c) == st.end()) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                continue;
            }
            count++;
        }
        return count;
    }
};
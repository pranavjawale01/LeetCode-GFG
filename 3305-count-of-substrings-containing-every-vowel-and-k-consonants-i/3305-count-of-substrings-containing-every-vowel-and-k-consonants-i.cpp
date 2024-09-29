class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int n = word.size();
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<char> vow;
            int conso = 0;
            for (int j = i; j < n; j++) {
                if (st.find(word[j]) != st.end()) {
                    vow.insert(word[j]);
                } else {
                    conso++;
                }
                if (vow.size() == 5 && conso == k) {
                    ans++;
                }
                if (conso > k) {
                    break;
                }
            }
        }
        return ans;
    }
};
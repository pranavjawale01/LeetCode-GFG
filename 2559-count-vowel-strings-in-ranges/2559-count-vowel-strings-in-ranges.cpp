class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pref(n, 0);
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
        
        for (int i = 0; i < n; i++) {
            if (i > 0) pref[i] += pref[i-1];
            if (st.count(words[i][0]) && st.count(words[i].back())) {
                pref[i]++;
            }
        }
        
        vector<int> ans;
        for (auto &x : queries) {
            int l = x[0], r = x[1];
            int temp = pref[r] - (l > 0 ? pref[l - 1] : 0);
            ans.push_back(temp);
        }
        
        return ans;
    }
};
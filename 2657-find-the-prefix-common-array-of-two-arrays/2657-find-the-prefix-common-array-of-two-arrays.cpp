class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mp;
        vector<int> ans;
        int n = A.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            mp[A[i]]++;
            mp[B[i]]++;
            if (A[i] == B[i]) {
                count++;
            } else {
                if (mp[A[i]] == 2) count++;
                if (mp[B[i]] == 2) count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> longestMatch(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    longestMatch[i][j] = 1;
                    if (i > 0) {
                        longestMatch[i][j] += longestMatch[i - 1][j - 1];
                    }
                }
            }
        }
        
        int result = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int len1 = i;
                int len2 = j - i;
                int len3 = n - j;
                
                if ((len1 <= len2 && longestMatch[i - 1][i - 1 + len1] == len1) ||
                    (len2 <= len3 && longestMatch[j - 1][j - 1 + len2] >= len2)) {
                    result++;
                }
            }
        }
        
        return result;
    }
};








// class Solution {
// public:
//     bool isPrefix(vector<long> &hash, int s1, int e1, int s2, int e2, long mod, vector<long> &pow) {
//         int len1 = e1 - s1;
//         int len2 = e2 - s2;
//         if (len1 > len2) return false;
//         long hash1 = (hash[e1] - (hash[s1] * pow[len1]) % mod + mod) % mod;
//         long hash2 = (hash[s2 + len1] - (hash[s2] * pow[len1]) % mod + mod) % mod;
//         return hash1 == hash2;
//     }
//     int beautifulSplits(vector<int>& nums) {
//         int n = nums.size();
//         if (n < 3) return 0;
//         long mod = 1e9 + 7;
//         long base = 31;
//         vector<long> prefixHash(n+1, 0);
//         vector<long> pow(n+1, 1);
//         for (int i = 0; i < n; i++) {
//             pow[i+1] = (pow[i] * base) % mod;
//             prefixHash[i+1] = (prefixHash[i] * base + nums[i]) % mod;
//         }
//         int count = 0;
//         for (int i = 1; i < n - 1; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 bool valid = false;
//                 if (isPrefix(prefixHash, 0, i, i, j, mod, pow)) valid = true;
//                 if (!valid && isPrefix(prefixHash, i, j, j, n, mod, pow)) valid = true;
//                 if (valid) count++;
//             }
//         }
//         return count;
//     }
// };
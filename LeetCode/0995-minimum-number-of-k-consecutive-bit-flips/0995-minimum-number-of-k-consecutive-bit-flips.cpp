class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        deque<int> flipq;
        int flipcount = 0;
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                flipcount -= flipq.front();
                flipq.pop_front();
            }
            if (flipcount % 2 == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                flipcount++;
                flipq.push_back(1);
                flips++;
            } else {
                flipq.push_back(0);
            }
        }
        return flips;
    }
};



// class Solution {
// public:
//     int minKBitFlips(vector<int>& nums, int k) {
//         int n = nums.size();
//         int ans = 0, times = 0;
//         vector<int> dp(n, 0);
//         for (int i = 0; i < n; i++) {
//             if (i >= k) {
//                 times -= dp[i-k];
//             }
//             if (nums[i] == 1 && times % 2 == 1 || nums[i] == 0 && times % 2 == 0) {
//                 if (i + k > n) {
//                     return -1;
//                 }
//                 ans++;
//                 times++;
//                 dp[i] = 1;
//             }
//         }
//         return ans;
//     }
// };




// TLE
// class Solution {
// public:
//     int minKBitFlips(vector<int>& nums, int k) {
//         int flip = 0;
//         int n = nums.size();
        
//         for (int i = 0; i <= n - k; i++) {
//             if (nums[i] == 0) {
//                 for (int j = i; j < i + k; j++) {
//                     nums[j] ^= 1;
//                 }
//                 flip++;
//             }
//         }
        
//         for (int i = n - k + 1; i < n; i++) {
//             if (nums[i] == 0) {
//                 return -1;
//             }
//         }
        
//         return flip;
//     }
// };
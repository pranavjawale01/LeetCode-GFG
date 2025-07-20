class Solution {
public:
    typedef long long ll;
    ll maximumValueSum(vector<int>& nums, int k,vector<vector<int>>& edges) {
        vector<int> fayda;
        ll normalSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            fayda.push_back((nums[i] ^ k) - nums[i]);
            normalSum += 1ll * nums[i];
        }
        
        sort(fayda.begin(), fayda.end(), greater<int>());
        
        for (int i = 0; i < fayda.size()-1; i += 2) {

            ll pairSum = fayda[i] + fayda[i + 1];
            
            if (pairSum > 0) {
                normalSum += pairSum;
            }
        }
        return normalSum;
    }
};


// class Solution {
// public:
//     long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
//         long long sum = 0;
//         int count = 0;
//         int minLoss = INT_MAX;
//         for (long long num : nums) {
//             if ((num ^ k) > num) {
//                 count++;
//                 sum += (num ^ k);
//             } else {
//                 sum += num;
//             }
//             minLoss = min((long long)minLoss, abs(num - (num ^ k)));
//         }
//         if (count % 2 == 0) {
//             return sum;
//         }
//         return sum - minLoss;
//     }
// };
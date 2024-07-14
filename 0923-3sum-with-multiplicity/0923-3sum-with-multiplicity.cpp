class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        int mod = 1e9+7;
        int count = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            count = (count + mp[target - arr[i]]) % mod;
            for (int j = 0; j < i; j++) {
                mp[arr[i] + arr[j]]++;
            }
        }
        return count;
    }
};





// class Solution {
// public:
//     int threeSumMulti(vector<int>& arr, int target) {
//         sort(arr.begin(), arr.end());
//         int n = arr.size();
//         long long count = 0;
//         int mod = 1e9 + 7;
//         for (int i = 0; i < n - 2; ++i) {
//             int j = i + 1, k = n - 1;
//             while (j < k) {
//                 int sum = arr[i] + arr[j] + arr[k];
//                 if (sum == target) {
//                     int left = 1, right = 1;
//                     while (j < k && arr[j] == arr[j + 1]) {
//                         left++;
//                         j++;
//                     }
//                     while (k > j && arr[k] == arr[k - 1]) {
//                         right++;
//                         k--;
//                     }
//                     if (j == k) {
//                         long long temp = (left * (left - 1)) / 2; 
//                         count = (count + temp) % mod;
//                     } else {
//                         count = (count + left * right) % mod;
//                     }
//                     j++;
//                     k--;
//                 } else if (sum > target) {
//                     k--;
//                 } else {
//                     j++;
//                 }
//             }
//         }
//         return count;
//     }
// };
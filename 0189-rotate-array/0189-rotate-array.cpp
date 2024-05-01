class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reverse(nums.begin(),nums.begin()+(nums.size()-k));
        reverse(nums.begin()+(nums.size()-k),nums.end());
        reverse(nums.begin(),nums.end());
    }
};



// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k = k % n; 
//         vector<int> temp;
//         for (int i = n - k; i < n; i++) {
//             temp.push_back(nums[i]);
//         }        
//         for (int i = n - 1; i >= k; i--) {
//             nums[i] = nums[i - k];
//         }
//         for (int i = 0; i < k; i++) {
//             nums[i] = temp[i];
//         }
//     }
// };
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> output(size);
        int p = 0, n = 1;
        for (int i = 0; i < size; i++) {
            if (nums[i] > 0) {
                output[p] = nums[i];
                p += 2;
            } else {
                output[n] = nums[i];
                n += 2;
            }
        }
        return output;
    }
};

// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int> pos, neg, output;
//         int n = nums.size();
//         for (int num : nums) {
//             if (num > 0) {
//                 pos.push_back(num);
//             } else {
//                 neg.push_back(num);
//             }
//         }
//         for (int i = 0; i < n / 2; i++) {
//             output.push_back(pos[i]);
//             output.push_back(neg[i]);
//         }
//         return output;
//     }
// };
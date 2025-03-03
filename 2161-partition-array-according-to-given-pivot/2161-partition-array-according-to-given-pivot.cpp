class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int less = 0, equal = 0;
        for (int &x : nums) {
            if (x < pivot) {
                less++;
            } else if (x == pivot) {
                equal++;
            }
        }
        int i = 0, j = less, k = less + equal;
        vector<int> ans(n);
        for (int &x : nums) {
            if (x < pivot) {
                ans[i] = x;
                i++;
            } else if (x == pivot) {
                ans[j] = x;
                j++;
            } else {
                ans[k] = x;
                k++;
            }
        }
        return ans;
    }
};







// class Solution {
// public:
//     vector<int> pivotArray(vector<int>& nums, int pivot) {
//         vector<int> ans1, ans2, ans3;
//         for (int x : nums) {
//             if (x < pivot) ans1.push_back(x);
//             if (x == pivot) ans2.push_back(x);
//             if (x > pivot) ans3.push_back(x);
//         }
//         vector<int> result;
//         result.insert(result.end(), ans1.begin(), ans1.end());
//         result.insert(result.end(), ans2.begin(), ans2.end());
//         result.insert(result.end(), ans3.begin(), ans3.end());
//         return result;
//     }
// };
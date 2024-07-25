class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<int> leftVec(n1);
        vector<int> rightVec(n2);

        for (int i = 0; i < n1; i++) {
            leftVec[i] = nums[left + i];
        }
        for (int j = 0; j < n2; j++) {
            rightVec[j] = nums[mid + 1 + j];
        }

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftVec[i] <= rightVec[j]) {
                nums[k] = leftVec[i];
                i++;
            } else {
                nums[k] = rightVec[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            nums[k] = leftVec[i];
            i++;
            k++;
        }

        while (j < n2) {
            nums[k] = rightVec[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);

            merge(nums, left, mid, right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};






// class Solution {
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         int minE = *min_element(nums.begin(), nums.end());
//         int maxE = *max_element(nums.begin(), nums.end());
//         unordered_map<int, int> mp;
//         for (auto &x : nums) {
//             mp[x]++;
//         }
//         int j = 0;
//         for (int i = minE; i <= maxE; i++) {
//             while (mp[i] > 0) {
//                 nums[j] = i;
//                 j++;
//                 mp[i]--;
//             }
//         }
//         return nums;
//     }
// };
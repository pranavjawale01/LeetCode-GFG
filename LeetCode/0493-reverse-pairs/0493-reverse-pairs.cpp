class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        int left = low;
        int right = mid + 1;
        vector<int> tmp;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                tmp.push_back(nums[left++]);
            } else {
                tmp.push_back(nums[right++]);
            }
        }

        while (left <= mid) {
            tmp.push_back(nums[left++]);
        }

        while (right <= high) {
            tmp.push_back(nums[right++]);
        }

        for (int i = low; i <= high; ++i) {
            nums[i] = tmp[i - low];
        }
    }

    int countPairs(vector<int>& nums, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;

        for (int i = low; i <= mid; ++i) {
            while (right <= high && (long long)nums[i] > (long long)2 * nums[right]) {
                ++right;
            }
            cnt += (right - (mid + 1));
        }

        return cnt;
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;
        int cnt = 0;

        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);
        cnt += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
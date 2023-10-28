class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int low = 0, high = nums.size() - 1;
        while (low <= high) 
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) 
            {
                int start = mid;
                int end = mid;
                while (start > 0 && nums[start - 1] == target) 
                {
                    start--;
                }
                while (end < nums.size() - 1 && nums[end + 1] == target) 
                {
                    end++;
                }
                result.push_back(start);
                result.push_back(end);
                return result;
            } 
            else if (nums[mid] < target) 
            {
                low = mid + 1;
            } 
            else 
            {
                high = mid - 1;
            }
        }
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
};
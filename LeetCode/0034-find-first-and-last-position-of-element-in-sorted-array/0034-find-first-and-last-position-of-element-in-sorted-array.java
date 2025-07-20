class Solution {
    public int[] searchRange(int[] nums, int target) {
        int low = 0, high = nums.length - 1;
        int[] result = {-1, -1};
        while (low <= high) 
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) 
            {
                int start = mid, end = mid;
                while (start > 0 && nums[start - 1] == target) 
                {
                    start--;
                }
                while (end < nums.length - 1 && nums[end + 1] == target) 
                {
                    end++;
                }
                result[0] = start;
                result[1] = end;
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
        return result;
    }
}
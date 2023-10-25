class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length, k = -1, l = -1;
        for (int i = n - 2; i >= 0; i--) 
        {
            if (nums[i] < nums[i + 1]) 
            {
                k = i;
                break;
            }
        }
        if (k == -1) 
        {
            Arrays.sort(nums);
        } 
        else 
        {
            for (int i = n - 1; i > k; i--) 
            {
                if (nums[i] > nums[k]) 
                {
                    l = i;
                    break;
                }
            }
            swap(nums, k, l);
            Arrays.sort(nums, k + 1, n);
        }
    }

    private void swap(int[] nums, int i, int j) 
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
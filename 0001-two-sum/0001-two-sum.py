class Solution 
{
    public int[] twoSum(int[] nums, int target) 
    {
        Map<Integer, Integer> numMap = new HashMap<Integer,Integer>();
        int n = nums.length;
        for (int i = 0; i < n; i++) 
        {
            int remaining = target - nums[i];
            if (numMap.containsKey(remaining)) 
            {
                return new int[]{numMap.get(remaining), i};
            }
            numMap.put(nums[i], i);
        }
        return new int[]{};
    }
}
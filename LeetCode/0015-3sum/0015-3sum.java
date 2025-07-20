class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        for(int i=0;i<nums.length;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int target = -nums[i];
            int front = i+1;
            int back = nums.length - 1;
            while(front<back)
            {
                int sum = nums[front] + nums[back];
                if(sum<target)
                {
                    front++;
                }
                else if(sum>target)
                {
                    back--;
                }
                else
                {
                    res.add(Arrays.asList(nums[i],nums[front],nums[back]));
                    while(front<back && nums[front]==nums[front+1])
                    {
                        front++;
                    }
                    while(front<back && nums[back]==nums[back-1])
                    {
                        back--;
                    }
                    front++;back--;
                }
            }
        }
        return res;
    }
}
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum = nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-2;i++)
        {
            int front = i+1, back = nums.size()-1;
            while(front<back)
            {
                int temp = nums[i]+nums[front]+nums[back];
                if(abs(temp-target)<abs(sum-target))
                {
                    sum = temp;
                }
                if(temp>target)
                {
                    back--;
                }
                else if(temp<target)
                {
                    front++;
                }
                else
                {
                    return sum;
                }
            }
        }
        return sum;
    }
};
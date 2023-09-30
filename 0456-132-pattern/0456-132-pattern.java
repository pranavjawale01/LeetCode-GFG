import java.util.Stack;

class Solution {
    public boolean find132pattern(int[] nums) {
        int n = nums.length;
        if (n < 3) 
        {
            return false;
        }
        int[] minIndex = new int[n];
        minIndex[0] = nums[0];
        for (int i = 1; i < n; i++) 
        {
            minIndex[i] = Math.min(nums[i], minIndex[i - 1]);
        }
        Stack<Integer> s = new Stack<>();
        for (int j = n - 1; j >= 0; j--) 
        {
            if (nums[j] > minIndex[j]) 
            {
                while (!s.isEmpty() && s.peek() <= minIndex[j]) 
                {
                    s.pop();
                }
                if (!s.isEmpty() && s.peek() < nums[j]) 
                {
                    return true;
                }
            }
            s.push(nums[j]);
        }
        return false;
    }
}
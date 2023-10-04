class Solution {
    public int maxArea(int[] height) {
        int left = 0, right = height.length-1, finalArea = 0, currArea = 0;
        while(left < right)
        {
            currArea = Math.min(height[left],height[right]) * (right - left);
            finalArea = Math.max(finalArea,currArea);
            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return finalArea;
    }
}
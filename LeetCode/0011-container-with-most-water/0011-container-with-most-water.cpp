class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left=0, right=height.size()-1, finalArea=0, currArea=0;
        while(left<right)
        {
            currArea = min(height[left], height[right]) * (right-left);
            finalArea = max(finalArea,currArea);
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
};
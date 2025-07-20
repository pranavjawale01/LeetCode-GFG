class Solution:
    def maxDistinctElements(self, nums: List[int], k: int) -> int:
        nums.sort()
        st = set()
        back = -k
        n = len(nums)
        
        for i in range(n):
            temp = max(back + 1, nums[i] - k)
            if temp <= nums[i] + k:
                st.add(temp)
                back = temp
        
        return len(st)
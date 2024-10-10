class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        st = []
        ans = 0
        for i in range(len(nums)):
            if not st or nums[st[-1]] > nums[i]:
                st.append(i)
        for i in range(len(nums)-1, -1, -1):
            while st and nums[st[-1]] <= nums[i]:
                ans = max(ans, i - st[-1])
                st.pop()
        return ans
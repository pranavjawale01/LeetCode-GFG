class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        s1 = set(nums1)
        s2 = set(nums2)
        ans = []
        for num in s2:
            if num in s1:
                ans.append(num)
        return ans
class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        set1 = set(nums1)
        set2 = set(nums2)
        
        ans1 = [num for num in set1 if num not in set2]
        ans2 = [num for num in set2 if num not in set1]
        
        return [ans1, ans2]
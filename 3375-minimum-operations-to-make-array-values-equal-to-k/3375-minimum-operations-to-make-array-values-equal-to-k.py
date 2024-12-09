class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        st = set(nums)
        m = min(nums)
        if m < k:
            return -1
        if m == k:
            return len(st) - 1
        else:
            return len(st)
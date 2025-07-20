class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        arr = [0] * 101
        ans , maxCount = 0, 0
        for num in nums:
            arr[num] += 1
            if maxCount == arr[num]:
                ans += arr[num]
            if arr[num] > maxCount:
                maxCount = arr[num]
                ans = arr[num]
        return ans

# class Solution:
#     def maxFrequencyElements(self, nums: List[int]) -> int:
#         mp = defaultdict(int)
#         ans , maxCount = 0, 0
#         for num in nums:
#             mp[num] += 1
#             maxCount = max(maxCount, mp[num])
#         for num, count in mp.items():
#             if count == maxCount:
#                 ans += count
#         return ans
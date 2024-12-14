class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        count_map = Counter()
        i = 0
        count = 0
        for j in range(n):
            count_map[nums[j]] += 1
            while max(count_map) - min(count_map) > 2:
                count_map[nums[i]] -= 1
                if count_map[nums[i]] == 0:
                    del count_map[nums[i]]
                i += 1
            count += j - i + 1
        return count
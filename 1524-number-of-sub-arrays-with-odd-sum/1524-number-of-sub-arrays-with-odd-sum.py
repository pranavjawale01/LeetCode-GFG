class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        ans = 0
        mod = 1000000007
        odd_count = 0
        even_count = 1
        prefix_sum = 0

        for num in arr:
            prefix_sum += num
            if prefix_sum % 2 == 0:
                ans = (ans + odd_count) % mod
                even_count += 1
            else:
                ans = (ans + even_count) % mod
                odd_count += 1

        return ans
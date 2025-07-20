class Solution:
    def sumOfGoodSubsequences(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        ans = 0
        n = len(nums)
        
        sum_map = {}
        count_map = {}

        for num in nums:
            ans = (ans + num) % MOD
            find1 = num + 1
            find2 = num - 1

            cnt1 = count_map.get(find1, 0)
            sum1 = sum_map.get(find1, 0)

            ans = (ans + (cnt1 * num % MOD + sum1) % MOD) % MOD

            cnt2 = count_map.get(find2, 0)
            sum2 = sum_map.get(find2, 0)

            ans = (ans + (cnt2 * num % MOD + sum2) % MOD) % MOD

            count_map[num] = (count_map.get(num, 0) + cnt1 + cnt2 + 1) % MOD
            curr = (num * (cnt1 + cnt2 + 1)) % MOD
            sum_map[num] = (sum_map.get(num, 0) + sum1 + sum2 + curr) % MOD

        return ans
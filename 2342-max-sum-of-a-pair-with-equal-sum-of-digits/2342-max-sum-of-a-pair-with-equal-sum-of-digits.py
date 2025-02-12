class Solution:
    def sum_of_digit(self, n: int) -> int:
        return sum(int(digit) for digit in str(n))
    
    def maximumSum(self, nums: List[int]) -> int:
        nums.sort()
        digit_sum_map = {}
        ans = -1

        for num in nums:
            s = self.sum_of_digit(num)
            if s in digit_sum_map:
                ans = max(ans, num + digit_sum_map[s])
            digit_sum_map[s] = num
        
        return ans
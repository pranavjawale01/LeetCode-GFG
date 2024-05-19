class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        sum_ = 0
        count = 0
        min_loss = float('inf')
        
        for num in nums:
            if (num ^ k) > num:
                count += 1
                sum_ += (num ^ k)
            else:
                sum_ += num
            min_loss = min(min_loss, abs(num - (num ^ k)))
        
        if count % 2 == 0:
            return sum_
        return sum_ - min_loss
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        count = {}
        for num in nums:
            count[num] = count.get(num, 0) + 1
            
        total = 0
        
        for c in count.values():
            if c == 1:
                return -1
            total += ceil(c / 3)
            
        return total
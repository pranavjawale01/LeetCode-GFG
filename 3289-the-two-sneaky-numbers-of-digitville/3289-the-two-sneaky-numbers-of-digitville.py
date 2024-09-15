class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        count = {}
        
        for num in nums:
            count[num] = count.get(num, 0) + 1
        
        sneaky_numbers = []
        
        for num, cnt in count.items():
            if cnt > 1:
                sneaky_numbers.append(num)
        
        return sneaky_numbers
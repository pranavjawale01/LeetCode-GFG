class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        result = []
        maxElement, i = 0, 1
        count = [0 for i in range(201)]
        for k in range(len(nums)):
            count[nums[k]] += 1
            maxElement = max(maxElement, count[nums[k]])
        
        while i <= maxElement:
            temp = []
            for j in range(201):
                if count[j] >= i:
                    temp.append(j)
            if temp:
                result.append(temp)
            
            i += 1
        return result
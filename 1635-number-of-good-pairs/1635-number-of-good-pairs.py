class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        result = 0
        countDict = {}
        for i in nums:
            if i in countDict:
                result += countDict[i]
                countDict[i] += 1
            else:
                countDict[i] = 1
        return result
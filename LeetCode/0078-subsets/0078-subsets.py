class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = [[]]

        for num in nums:
            n = len(result)
            for j in range(n):
                subset = result[j].copy()
                subset.append(num)
                result.append(subset)

        return result
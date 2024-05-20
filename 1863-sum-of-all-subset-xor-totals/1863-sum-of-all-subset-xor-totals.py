class Solution:
    def solve(self, nums, i, curr_subset, subsets):
        if i == len(nums):
            subsets.append(curr_subset.copy())
            return
        curr_subset.append(nums[i])
        self.solve(nums, i+1, curr_subset, subsets)
        curr_subset.pop()
        self.solve(nums, i+1, curr_subset, subsets)
        
    def subsetXORSum(self, nums: List[int]) -> int:
        subsets = []
        curr_subset = []
        self.solve(nums, 0, curr_subset, subsets)
        result = 0
        for subset in subsets:
            xor_sum = 0
            for num in subset:
                xor_sum ^= num
            result += xor_sum
        return result
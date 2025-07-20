class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        pos = []
        neg = []
        output = []
        n = len(nums)
        
        for num in nums:
            if num > 0:
                pos.append(num)
            else:
                neg.append(num)
        
        for i in range(n // 2):
            output.append(pos[i])
            output.append(neg[i])
        
        return output
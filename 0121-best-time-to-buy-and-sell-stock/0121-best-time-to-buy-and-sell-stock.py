class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxPrice, minPrice = 0, float('inf')
        for i in range(len(prices)):
            minPrice = min(minPrice, prices[i])
            maxPrice = max(maxPrice, prices[i] - minPrice)
        return maxPrice

# class Solution:
#     def maxProfit(self, prices: List[int]) -> int:
#         currMax = 0
#         finalMax = 0
#         n = len(prices)
#         for i in range(1, n):
#             currMax = max(0, currMax + prices[i] - prices[i-1])
#             finalMax = max(finalMax, currMax)
#         return finalMax
class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n = len(prices)
        st = []
        for i in range(n):
            while st and prices[i] <= prices[st[-1]]:
                prices[st[-1]] -= prices[i]
                st.pop()
            st.append(i)
        return prices




# class Solution:
#     def finalPrices(self, prices: List[int]) -> List[int]:
#         n = len(prices)
#         for i in range(n):
#             for j in range(i+1, n):
#                 if prices[i] >= prices[j]:
#                     prices[i] -= prices[j]
#                     break
#         return prices
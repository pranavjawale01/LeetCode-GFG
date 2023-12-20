class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        prices.sort()
        return money - prices[0] - prices[1] if money - prices[0] - prices[1] >= 0 else money
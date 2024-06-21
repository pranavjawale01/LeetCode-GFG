class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        n = len(grumpy)
        ans = 0
        for i in range(n):
            if grumpy[i] == 0:
                ans += customers[i]
        temp1 = ans
        for i in range(n-minutes+1):
            temp = temp1
            for j in range(i, i+minutes):
                if grumpy[j] == 1:
                    temp += customers[j]
            ans = max(ans, temp)
        return ans
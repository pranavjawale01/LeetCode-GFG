class Solution:
    def maximumTotalSum(self, maximumHeight: List[int]) -> int:
        n = len(maximumHeight)
        ans = 0
        maximumHeight.sort()
        currHt = maximumHeight[-1]
        
        for i in range(n - 1, -1, -1):
            if currHt > maximumHeight[i]:
                currHt = maximumHeight[i]
            if currHt < 1:
                return -1
            ans += currHt
            currHt -= 1
            
        return ans
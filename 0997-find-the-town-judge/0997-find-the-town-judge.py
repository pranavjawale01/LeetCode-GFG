class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        if not trust:
            return -1
        
        count = [0] * (n + 1)
        for i in range(len(trust)):
            a, b = trust[i][0], trust[i][1]
            count[a] -= 1
            count[b] += 1
        for i in range(1, n + 1):
            if count[i] == n - 1:
                return i
        return -1
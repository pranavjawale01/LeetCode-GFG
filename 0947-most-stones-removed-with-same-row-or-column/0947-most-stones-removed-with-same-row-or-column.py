class Solution:
    
    def __init__(self):
        self.n = 0
    
    def dfs(self, stones: List[List[int]], idx: int, vis: List[bool]) -> None:
        vis[idx] = True
        for i in range(self.n):
            if not vis[i] and (stones[i][0] == stones[idx][0] or stones[i][1] == stones[idx][1]):
                self.dfs(stones, i, vis)
    
    def removeStones(self, stones: List[List[int]]) -> int:
        self.n = len(stones)
        vis = [False] * self.n
        count = 0
        for i in range(self.n):
            if vis[i]:
                continue
            self.dfs(stones, i, vis)
            count += 1
        return self.n - count
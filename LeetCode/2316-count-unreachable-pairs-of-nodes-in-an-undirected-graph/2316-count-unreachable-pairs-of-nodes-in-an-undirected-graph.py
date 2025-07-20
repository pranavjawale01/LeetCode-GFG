class Solution:
    def __init__(self):
        self.parent = []
        self.rank = []

    def find(self, i):
        if self.parent[i] == i:
            return i
        self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    def DSU(self, x, y):
        par_x = self.find(x)
        par_y = self.find(y)
        if par_x != par_y:
            if self.rank[par_y] > self.rank[par_x]:
                self.parent[par_x] = par_y
            elif self.rank[par_y] < self.rank[par_x]:
                self.parent[par_y] = par_x
            else:
                self.parent[par_x] = par_y
                self.rank[par_y] += 1

    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        self.parent = [i for i in range(n)]
        self.rank = [0] * n
        for edge in edges:
            self.DSU(edge[0], edge[1])

        mp = {}
        for i in range(n):
            father = self.find(i)
            if father in mp:
                mp[father] += 1
            else:
                mp[father] = 1

        result = 0
        remaining = n
        for size in mp.values():
            result += size * (remaining - size)
            remaining -= size

        return result
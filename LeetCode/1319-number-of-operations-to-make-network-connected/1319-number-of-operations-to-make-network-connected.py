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
            if self.rank[par_x] > self.rank[par_y]:
                self.parent[par_y] = par_x
            elif self.rank[par_x] < self.rank[par_y]:
                self.parent[par_x] = par_y
            else:
                self.parent[par_x] = par_y
                self.rank[par_y] += 1

    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        edges = len(connections)
        if edges < n - 1:
            return -1

        self.parent = [i for i in range(n)]
        self.rank = [0] * n

        count = n
        for x in connections:
            if self.find(x[0]) != self.find(x[1]):
                self.DSU(x[0], x[1])
                count -= 1

        return count - 1
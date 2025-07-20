class Solution:
    def __init__(self):
        self.parent = [i for i in range(26)]
        self.rank = [1] * 26

    def find(self, i):
        if self.parent[i] == i:
            return i
        self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    def union(self, x, y):
        parX = self.find(x)
        parY = self.find(y)

        if parX != parY:
            if self.rank[parX] > self.rank[parY]:
                self.parent[parY] = parX
            elif self.rank[parX] < self.rank[parY]:
                self.parent[parX] = parY
            else:
                self.parent[parY] = parX
                self.rank[parX] += 1

    def equationsPossible(self, equations: List[str]) -> bool:
        for eq in equations:
            if eq[1] == '=':
                self.union(ord(eq[0]) - ord('a'), ord(eq[3]) - ord('a'))

        for eq in equations:
            if eq[1] == '!':
                if self.find(ord(eq[0]) - ord('a')) == self.find(ord(eq[3]) - ord('a')):
                    return False

        return True
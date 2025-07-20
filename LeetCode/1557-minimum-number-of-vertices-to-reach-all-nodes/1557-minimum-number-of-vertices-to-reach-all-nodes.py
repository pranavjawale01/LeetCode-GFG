class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        inDegree = [0] * n
        for edge in edges:
            inDegree[edge[1]] += 1
        ans = []
        for i in range(n):
            if inDegree[i] == 0:
                ans.append(i)
        return ans
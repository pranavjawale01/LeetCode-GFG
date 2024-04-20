class Solution:
    def findFarmland(self, land):
        row = len(land)
        col = len(land[0])
        ans = []
        for i in range(row):
            for j in range(col):
                if land[i][j] == 1:
                    i_max = i
                    while i_max < row and land[i_max][j] == 1:
                        i_max += 1
                    j_max = j
                    while j_max < col and land[i][j_max] == 1:
                        j_max += 1
                    i_max = i_max - 1 if i_max > 0 else i_max
                    j_max = j_max - 1 if j_max > 0 else j_max
                    ans.append([i, j, i_max, j_max])
                    for k in range(i, i_max + 1):
                        for l in range(j, j_max + 1):
                            land[k][l] = 0
        return ans
     
# class Solution:
#     def bfs(self, land, i, j, row, col, max_i, max_j):
#         directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
#         q = deque([(i, j)])
#         while q:
#             p = q.popleft()
#             max_i[0] = max(max_i[0], p[0])
#             max_j[0] = max(max_j[0], p[1])
#             for dir in directions:
#                 i_ = p[0] + dir[0]
#                 j_ = p[1] + dir[1]
#                 if 0 <= i_ < row and 0 <= j_ < col and land[i_][j_] == 1:
#                     land[i_][j_] = 0
#                     q.append((i_, j_))

#     def findFarmland(self, land):
#         row = len(land)
#         col = len(land[0])
#         ans = []
#         for i in range(row):
#             for j in range(col):
#                 if land[i][j] == 1:
#                     max_i = [i]
#                     max_j = [j]
#                     self.bfs(land, i, j, row, col, max_i, max_j)
#                     ans.append([i, j, max_i[0], max_j[0]])
#         return ans

# class Solution:
#     def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
#         row, col = len(land), len(land[0])
#         ans = []

#         def dfs(land, i, j, row, col, max_coords):
#             if i < 0 or j < 0 or i >= row or j >= col or land[i][j] == 0:
#                 max_coords[0] = max(i-1, max_coords[0])
#                 max_coords[1] = max(j-1, max_coords[1])
#                 return
#             land[i][j] = 0
#             max_coords[0] = max(i, max_coords[0])
#             max_coords[1] = max(j, max_coords[1])
#             dfs(land, i+1, j, row, col, max_coords)
#             dfs(land, i-1, j, row, col, max_coords)
#             dfs(land, i, j+1, row, col, max_coords)
#             dfs(land, i, j-1, row, col, max_coords)

#         for i in range(row):
#             for j in range(col):
#                 if land[i][j] == 1:
#                     max_coords = [i, j]
#                     dfs(land, i, j, row, col, max_coords)
#                     ans.append([i, j, max_coords[0], max_coords[1]])

#         return ans
class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        q = deque()
        row, col = len(mat), len(mat[0])
        level = 1
        for i in range(row):
            for j in range(col):
                if mat[i][j] == 0:
                    q.append([i, j])
                else:
                    mat[i][j] = -1

        dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]

        while q:
            n = len(q)
            while n:
                temp = q.popleft()
                for dir in dirs:
                    i = temp[0] + dir[0]
                    j = temp[1] + dir[1]
                    if i < 0 or j < 0 or i >= row or j >= col or mat[i][j] != -1:
                        continue
                    mat[i][j] = level
                    q.append([i, j])
                n -= 1
            level += 1
        
        return mat
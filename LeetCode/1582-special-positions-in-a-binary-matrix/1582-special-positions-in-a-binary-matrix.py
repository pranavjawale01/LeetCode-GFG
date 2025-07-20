class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        row = [0] * len(mat)
        col = [0] * len(mat[0])
        count = 0
        
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                row[i] += mat[i][j]
                col[j] += mat[i][j]
        
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                if mat[i][j] == 1 and row[i] == 1 and col[j] == 1:
                    count += 1
                
        return count
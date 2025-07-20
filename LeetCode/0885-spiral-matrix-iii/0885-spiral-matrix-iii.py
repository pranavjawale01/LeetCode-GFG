class Solution:
    def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> List[List[int]]:
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        ans = [[rStart, cStart]]
        step = 0
        dir = 0
        
        while len(ans) < rows * cols:
            if dir == 0 or dir == 2:
                step += 1
            for _ in range(step):
                rStart += dirs[dir][0]
                cStart += dirs[dir][1]
                if 0 <= rStart < rows and 0 <= cStart < cols:
                    ans.append([rStart, cStart])
            dir = (dir + 1) % 4
        
        return ans
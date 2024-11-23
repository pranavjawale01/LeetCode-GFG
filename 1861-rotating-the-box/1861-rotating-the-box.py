class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m, n = len(box), len(box[0])
        ans = [[''] * m for _ in range(n)]

        for i in range(m):
            for j in range(n):
                ans[j][m - 1 - i] = box[i][j]

        for j in range(m):
            for i in range(n - 1, -1, -1):
                if ans[i][j] == '.':
                    stone_row = -1
                    for k in range(i - 1, -1, -1):
                        if ans[k][j] == '*':
                            break
                        if ans[k][j] == '#':
                            stone_row = k
                            break
                    if stone_row != -1:
                        ans[i][j] = '#'
                        ans[stone_row][j] = '.'

        return ans
class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        mp = defaultdict(list)
        m, n = len(mat), len(mat[0])

        for i in range(m):
            for j in range(n):
                diagonal_sum = i + j
                mp[diagonal_sum].append(mat[i][j])

        ans = []
        flag = True
        for key, diagonal_elements in sorted(mp.items()):
            if flag:
                diagonal_elements.reverse()
            ans.extend(diagonal_elements)
            flag = not flag

        return ans
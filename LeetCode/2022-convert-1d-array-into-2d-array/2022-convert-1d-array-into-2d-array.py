class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        len_ = len(original)
        if len_ != m * n:
            return []
        ans = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(len_):
            ans[i // n][i % n] = original[i]
        return ans
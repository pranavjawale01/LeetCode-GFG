class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        dp = [[[None] * (n + 1) for _ in range(n)] for _ in range(2)]

        def solve(i: int, m: int, person: int) -> int:
            if i >= n:
                return 0
            if dp[person][i][m] is not None:
                return dp[person][i][m]

            result = 0 if person == 1 else float('inf')
            total = 0
            for x in range(1, min(2 * m, n - i) + 1):
                total += piles[i + x - 1]
                if person == 1:
                    result = max(result, total + solve(i + x, max(m, x), 0))
                else:
                    result = min(result, solve(i + x, max(m, x), 1))

            dp[person][i][m] = result
            return result

        return solve(0, 1, 1)
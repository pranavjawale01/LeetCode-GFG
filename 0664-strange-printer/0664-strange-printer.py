class Solution:
    def strangePrinter(self, s: str) -> int:
        n = len(s)
        dp = [[-1 for _ in range(n+1)] for _ in range(n+1)]
        def solve(l, r) -> int:
            if l == r:
                return 1
            if l > r:
                return 
            if dp[l][r] != -1:
                return dp[l][r]
            i = l + 1
            while i <= r and s[i] == s[l]:
                i += 1
            if i == r + 1:
                return 1
            basic = 1 + solve(i, r)
            greedy = float('inf')
            for j in range(i, r+1):
                if s[j] == s[l]:
                    ans = solve(i, j-1) + solve(j, r)
                    greedy = min(greedy, ans)
            dp[l][r] = min(basic, greedy)
            return dp[l][r]
        
        return solve(0, n-1)

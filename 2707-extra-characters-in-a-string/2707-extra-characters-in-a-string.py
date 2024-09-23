class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        n = len(s)
        dp = [-1] * (n + 1)
        word_set = set(dictionary)
        
        def solve(i: int) -> int:
            if i >= n:
                return 0
            
            if dp[i] != -1:
                return dp[i]
            
            result = 1 + solve(i + 1)
            
            for j in range(i, n):
                curr = s[i:j + 1]
                if curr in word_set:
                    result = min(result, solve(j + 1))
            
            dp[i] = result
            return result
        
        return solve(0)
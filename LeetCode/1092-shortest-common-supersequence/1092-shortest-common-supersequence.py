class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        m, n = len(str1), len(str2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(m + 1):
            for j in range(n + 1):
                if i == 0 or j == 0:
                    dp[i][j] = i + j
                elif str1[i - 1] == str2[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1])

        ans = []
        i, j = m, n
        while i > 0 and j > 0:
            if str1[i - 1] == str2[j - 1]:
                ans.append(str1[i - 1])
                i -= 1
                j -= 1
            elif dp[i - 1][j] < dp[i][j - 1]:
                ans.append(str1[i - 1])
                i -= 1
            else:
                ans.append(str2[j - 1])
                j -= 1

        while i > 0:
            ans.append(str1[i - 1])
            i -= 1
        while j > 0:
            ans.append(str2[j - 1])
            j -= 1

        return ''.join(reversed(ans))
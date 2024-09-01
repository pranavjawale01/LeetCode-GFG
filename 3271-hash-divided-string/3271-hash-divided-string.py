class Solution:
    def stringHash(self, s: str, k: int) -> str:
        ans = []
        n = len(s)

        for i in range(0, n, k):
            sum_val = 0
            for j in range(i, min(i + k, n)):
                sum_val += (ord(s[j]) - ord('a'))
            sum_val %= 26
            ans.append(chr(sum_val + ord('a')))
        
        return ''.join(ans)
class Solution:
    def rev(self, s: list, i: int, j: int):
        while i < j:
            s[i], s[j] = s[j], s[i]
            i += 1
            j -= 1

    def getEncryptedString(self, s: str, k: int) -> str:
        n = len(s)
        k = k % n
        s = list(s)
        self.rev(s, 0, k - 1)
        self.rev(s, k, n - 1)
        self.rev(s, 0, n - 1)
        return ''.join(s)
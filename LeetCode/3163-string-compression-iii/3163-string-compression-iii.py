class Solution:
    def compressedString(self, word: str) -> str:
        ans = ""
        count = 1
        n = len(word)

        for i in range(n):
            if i + 1 < n and word[i] == word[i + 1] and count < 9:
                count += 1
            else:
                ans += str(count) + word[i]
                count = 1

        return ans
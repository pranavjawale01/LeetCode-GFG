class Solution:
    def minimumPushes(self, word: str) -> int:
        freq = [0] * 26
        for c in word:
            freq[ord(c) - ord('a')] += 1
        freq.sort(reverse=True)
        ans = 0
        for i in range(26):
            ans += ((i // 8) + 1) * freq[i]
        return ans
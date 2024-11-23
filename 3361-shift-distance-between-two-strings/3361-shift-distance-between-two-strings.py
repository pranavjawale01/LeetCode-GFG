class Solution:
    def shiftDistance(self, s: str, t: str, nextCost: List[int], previousCost: List[int]) -> int:
        n = len(s)
        ans = 0
        for i in range(n):
            start = ord(s[i]) - ord('a')
            end = ord(t[i]) - ord('a')
            fs = (end - start + 26) % 26
            front = 0
            for j in range(fs):
                x = (start + j) % 26
                front += nextCost[x]
            bs = (start - end + 26) % 26
            back = 0
            for j in range(bs):
                x = (start - j + 26) % 26
                back += previousCost[x]
            ans += min(front, back)
        return ans
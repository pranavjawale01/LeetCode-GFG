class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        last = colors[0]
        ans = 0
        count = 1
        n = len(colors)
        for i in range(1, n):
            if colors[i] != last:
                count += 1
            else:
                count = 1
            if count >= k:
                ans += 1
            last = colors[i]

        for i in range(k-1):
            if colors[i] != last:
                count += 1
            else:
                count = 1

            if count >= k:
                ans += 1
            last = colors[i]
            
        return ans
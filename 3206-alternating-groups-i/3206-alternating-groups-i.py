class Solution:
    def numberOfAlternatingGroups(self, colors: List[int]) -> int:
        n = len(colors)
        count = 0
        for i in range(n-2):
            if colors[i] == colors[i+2] and colors[i] != colors[i+1]:
                count += 1
        if colors[0] == colors[n-2] and colors[0] != colors[n-1]:
            count += 1
        if colors[1] == colors[n-1] and colors[1] != colors[0]:
            count += 1
        return count
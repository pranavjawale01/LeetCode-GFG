class Solution:
    def maxDistance(self, s: str, k: int) -> int:
        north = south = east = west = 0
        ans = 0
        
        for c in s:
            if c == 'N': north += 1
            if c == 'S': south += 1
            if c == 'E': east += 1
            if c == 'W': west += 1
            
            maxVertical = max(north, south)
            minVertical = min(north, south)
            maxHorizontal = max(west, east)
            minHorizontal = min(west, east)
            kChanges = min(k, minVertical + minHorizontal)
            
            ans = max(ans, maxVertical + maxHorizontal - minVertical - minHorizontal + 2 * kChanges)
        
        return ans
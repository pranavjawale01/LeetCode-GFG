class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        mp = defaultdict(int)
        
        for a, b in intervals:
            b += 1
            mp[a] += 1
            mp[b] -= 1
        
        maxGrp, curGrp = 0, 0
        
        for k in sorted(mp.keys()):
            curGrp += mp[k]
            maxGrp = max(maxGrp, curGrp)
        
        return maxGrp
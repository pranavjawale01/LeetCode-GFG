class Solution:
    def minSteps(self, s: str, t: str) -> int:
        mp = defaultdict(int)
        
        for charS, charT in zip(s,t):
            mp[charS] -= 1
            mp[charT] += 1
            
        count = 0
        
        for charT in t:
            if mp[charT] > 0:
                count += mp[charT]
                mp[charT] = 0
                
        return count
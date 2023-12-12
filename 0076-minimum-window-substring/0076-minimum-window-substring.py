class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(s) == 0 or len(t) == 0 or len(s) < len(t):
            return ""
        
        tMap = defaultdict(int)
        
        for c in t:
            tMap[c] += 1
            
        left, right, count = 0, 0, len(t)
        min_len, min_left = float('inf'), 0
        len1, len2 = len(s), len(t)
        
        while right < len1:
            if tMap[s[right]] > 0:
                count -= 1
            tMap[s[right]] -= 1
            right += 1
            
            while count == 0:
                if right - left < min_len:
                    min_len = right - left
                    min_left = left
                
                tMap[s[left]] += 1
                if tMap[s[left]] > 0:
                    count += 1
                left += 1
                
        if min_len == float('inf'):
            return ""
        return s[min_left:min_left + min_len]
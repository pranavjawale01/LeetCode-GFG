class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        count = [0] * 26
        for ch in s:
            count[ord(ch) - ord('a')] += 1
        
        result = []
        i = 25
        
        while i >= 0:
            if count[i] == 0:
                i -= 1
                continue
            
            ch = chr(ord('a') + i)
            freq = min(count[i], repeatLimit)
            
            result.extend([ch] * freq)
            count[i] -= freq
            
            if count[i] > 0:
                j = i - 1
                while j >= 0 and count[j] == 0:
                    j -= 1
                
                if j < 0:
                    break
                
                result.append(chr(ord('a') + j))
                count[j] -= 1
        
        return ''.join(result)
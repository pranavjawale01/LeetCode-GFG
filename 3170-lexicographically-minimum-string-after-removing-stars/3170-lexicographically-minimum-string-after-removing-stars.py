class Solution:
    def clearStars(self, s: str) -> str:
        n = len(s)
        buckets = [[] for _ in range(26)]
        removed = [False] * n
        
        for i in range(n):
            if s[i] == '*':
                removed[i] = True
                for j in range(26):
                    if buckets[j]:
                        removed[buckets[j].pop()] = True
                        break
            else:
                buckets[ord(s[i]) - ord('a')].append(i)
        
        result = []
        for i in range(n):
            if not removed[i]:
                result.append(s[i])
        
        return ''.join(result)
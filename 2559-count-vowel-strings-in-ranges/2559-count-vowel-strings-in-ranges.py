class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        n = len(words)
        pref = [0] * n
        st = {'a', 'e', 'i', 'o', 'u'}
        
        for i in range(n):
            if i > 0:
                pref[i] += pref[i - 1]
            if words[i][0] in st and words[i][-1] in st:
                pref[i] += 1
        
        ans = []
        for query in queries:
            l, r = query
            temp = pref[r] - (pref[l - 1] if l > 0 else 0)
            ans.append(temp)
        
        return ans
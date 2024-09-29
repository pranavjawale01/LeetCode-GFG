class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        n = len(word)
        vowels = {'a', 'e', 'i', 'o', 'u'}
        ans = 0
        
        for i in range(n):
            vow_set = set()
            conso_count = 0
            
            for j in range(i, n):
                if word[j] in vowels:
                    vow_set.add(word[j])
                else:
                    conso_count += 1
                
                if len(vow_set) == 5 and conso_count == k:
                    ans += 1
                
                if conso_count > k:
                    break
                
        return ans
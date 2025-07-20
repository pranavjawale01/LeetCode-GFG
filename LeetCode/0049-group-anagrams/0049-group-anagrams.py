class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_map = defaultdict(list)

        for word in strs:
            key = ''.join(sorted(word))
            anagram_map[key].append(word)
        
        result = list(anagram_map.values())
        return result
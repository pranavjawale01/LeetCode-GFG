class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        st = set(allowed)
        count = 0
        for s in words:
            flag = False
            for c in s:
                if c not in st:
                    flag = True
                    break
            if flag:
                continue
            count += 1
        return count
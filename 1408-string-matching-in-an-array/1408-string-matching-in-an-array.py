class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        ans = []
        for x in words:
            for y in words:
                if x == y:
                    continue
                if x in y:
                    ans.append(x)
                    break
        return ans
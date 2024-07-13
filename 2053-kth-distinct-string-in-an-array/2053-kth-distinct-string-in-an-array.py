class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        mp = {}
        for x in arr:
            if x in mp:
                mp[x] += 1
            else:
                mp[x] = 1
        for x in arr:
            if mp[x] == 1:
                k -= 1
                if k == 0:
                    return x
        return ""
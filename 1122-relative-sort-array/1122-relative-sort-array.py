class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        mp = {}
        for x in arr1:
            if x in mp:
                mp[x] += 1
            else:
                mp[x] = 1
        ans = []
        for x in arr2:
            while mp[x] > 0:
                ans.append(x)
                mp[x] -= 1
            del mp[x]
        for k in sorted(mp.keys()):
            while mp[k] > 0:
                ans.append(k)
                mp[k] -= 1
        return ans
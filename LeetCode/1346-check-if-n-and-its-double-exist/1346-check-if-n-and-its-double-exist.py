class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        mp = {}
        for x in arr:
            if x not in mp:
                mp[x] = 1
            else:
                mp[x] += 1
        for x in arr:
            if 2 * x in mp:
                if x != 0 or mp[0] > 1:
                    return True
        return False
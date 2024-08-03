class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        mp = {}
        for x in target:
            if x not in mp:
                mp[x] = 1
            else:
                mp[x] += 1
        for x in arr:
            if x not in mp:
                return False
            mp[x] -= 1
            if mp[x] == 0:
                del mp[x]
        return len(mp) == 0




# class Solution:
#     def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
#         arr.sort()
#         target.sort()
#         return True if arr == target else False
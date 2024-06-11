class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        mp = {val: idx for idx, val in enumerate(arr2)}
        largeval = 1000000000
        for num in arr1:
            if num not in mp:
                mp[num] = largeval
        def cmp(num1, num2):
            i1 = mp[num1]
            i2 = mp[num2]
            if i1 == i2:
                return num1 - num2
            return i1 - i2
        arr1.sort(key = lambda x : (mp[x], x))
        return arr1


# class Solution:
#     def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
#         mp = {}
#         for x in arr1:
#             if x in mp:
#                 mp[x] += 1
#             else:
#                 mp[x] = 1
#         ans = []
#         for x in arr2:
#             while mp[x] > 0:
#                 ans.append(x)
#                 mp[x] -= 1
#             del mp[x]
#         for k in sorted(mp.keys()):
#             while mp[k] > 0:
#                 ans.append(k)
#                 mp[k] -= 1
#         return ans
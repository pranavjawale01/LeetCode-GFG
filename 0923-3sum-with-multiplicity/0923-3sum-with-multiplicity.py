class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        n = len(arr)
        mod = 10**9 + 7
        count = 0
        mp = {}
        for i in range(n):
            if target - arr[i] in mp:
                count = (count + mp[target - arr[i]]) % mod
            for j in range(0, i):
                if arr[i] + arr[j] in mp:
                    mp[arr[i] + arr[j]] += 1
                else:
                    mp[arr[i] + arr[j]] = 1
        return count





# class Solution:
#     def threeSumMulti(self, arr: List[int], target: int) -> int:
#         arr.sort()
#         n = len(arr)
#         count = 0
#         mod = 10**9 + 7

#         for i in range(n - 2):
#             j, k = i + 1, n - 1
#             while j < k:
#                 _sum = arr[i] + arr[j] + arr[k]
#                 if _sum == target:
#                     left, right = 1, 1
#                     while j < k and arr[j] == arr[j + 1]:
#                         left += 1
#                         j += 1
#                     while k > j and arr[k] == arr[k - 1]:
#                         right += 1
#                         k -= 1
#                     if j == k:
#                         temp = (left * (left - 1)) // 2
#                         count = (count + temp) % mod
#                     else:
#                         count = (count + left * right) % mod
#                     j += 1
#                     k -= 1
#                 elif _sum > target:
#                     k -= 1
#                 else:
#                     j += 1
        
#         return count
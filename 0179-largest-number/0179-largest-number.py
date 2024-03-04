class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        def compare(n1, n2):
            if n1+n2>n2+n1:
                return -1
            else:
                return 1
        nums = [str(i) for i in nums]
        nums = sorted(nums, key=cmp_to_key(compare))
        return str(int(''.join(nums)))

# class Compare(str):
#     def __lt__(x, y):
#         return x+y > y+x

# class Solution:
#     def largestNumber(self, nums: List[int]) -> str:
#         nums = list(map(str,nums))
#         nums.sort(key = Compare)
#         ans = ''.join(nums)
#         if ans[0] == '0':
#             return '0'
#         else:
#             return ans
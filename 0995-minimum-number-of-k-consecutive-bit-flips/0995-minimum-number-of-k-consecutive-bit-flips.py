class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        n = len(nums)
        flips = 0
        flipQue = deque()
        flipCountFromPastForCurri = 0

        for i in range(n):
            if i >= k:
                flipCountFromPastForCurri -= flipQue.popleft()

            if flipCountFromPastForCurri % 2 == nums[i]:
                if i + k > n:
                    return -1
                flipCountFromPastForCurri += 1
                flipQue.append(1)
                flips += 1
            else:
                flipQue.append(0)

        return flips




# class Solution:
#     def minKBitFlips(self, nums: List[int], k: int) -> int:
#         n = len(nums)
#         flips = 0
#         flipCountFromPastForCurri = 0

#         for i in range(n):
#             if i >= k and nums[i - k] == 2:
#                 flipCountFromPastForCurri -= 1

#             if flipCountFromPastForCurri % 2 == nums[i]:
#                 if i + k > n:
#                     return -1
#                 flipCountFromPastForCurri += 1
#                 nums[i] = 2
#                 flips += 1

#         return flips




# class Solution:
#     def minKBitFlips(self, nums: List[int], k: int) -> int:
#         n = len(nums)
#         flips = 0
#         isFlipped = [False] * n
#         flipCountFromPastForCurri = 0

#         for i in range(n):
#             if i >= k and isFlipped[i - k]:
#                 flipCountFromPastForCurri -= 1

#             if flipCountFromPastForCurri % 2 == nums[i]:
#                 if i + k > n:
#                     return -1
#                 flipCountFromPastForCurri += 1
#                 isFlipped[i] = True
#                 flips += 1

#         return flips
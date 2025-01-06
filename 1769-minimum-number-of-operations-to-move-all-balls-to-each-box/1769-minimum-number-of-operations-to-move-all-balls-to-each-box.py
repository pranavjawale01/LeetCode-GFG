class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        ans = [0] * n
        cumVal = cumSum = 0

        for i in range(n):
            ans[i] = cumSum
            cumVal += 0 if boxes[i] == '0' else 1
            cumSum += cumVal

        cumVal = cumSum = 0

        for i in range(n - 1, -1, -1):
            ans[i] += cumSum
            cumVal += 0 if boxes[i] == '0' else 1
            cumSum += cumVal

        return ans





# class Solution:
#     def minOperations(self, boxes: str) -> List[int]:
#         n = len(boxes)
#         ans = [0] * n
#         for i in range(n):
#             if boxes[i] == '1':
#                 for j in range(n):
#                     ans[j] += abs(j-i)
#         return ans
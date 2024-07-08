class Solution:
    def solve(self, n: int, k: int) -> int:
        if n == 1:
            return 0
        i = self.solve(n-1, k)
        i = (i + k) % n
        return i

    def findTheWinner(self, n: int, k: int) -> int:
        return 1 + self.solve(n, k)




# class Solution:
#     def findTheWinner(self, n: int, k: int) -> int:
#         q = deque(range(1, n+1))
#         while len(q) > 1:
#             for i in range(k-1):
#                 q.append(q.popleft())
#             q.popleft()
#         return q.popleft()




# class Solution:
#     def findTheWinner(self, n: int, k: int) -> int:
#         arr = []
#         for i in range(n):
#             arr.append(i+1)
#         i = 0
#         while len(arr) > 1:
#             i = (i + k - 1) % len(arr)
#             arr.pop(i)
#         return arr[0]
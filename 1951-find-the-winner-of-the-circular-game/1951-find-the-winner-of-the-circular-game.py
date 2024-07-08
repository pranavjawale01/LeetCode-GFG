class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        q = deque(range(1, n+1))
        while len(q) > 1:
            for i in range(k-1):
                q.append(q.popleft())
            q.popleft()
        return q.popleft()




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
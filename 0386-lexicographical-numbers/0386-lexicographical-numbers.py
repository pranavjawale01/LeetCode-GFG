class Solution:
    def solve(self, curr: int, n: int, ans: List[int]):
        if curr > n:
            return
        ans.append(curr)
        for i in range(0, 10):
            next = curr * 10 + i
            if next > n:
                return
            self.solve(next, n, ans)

    def lexicalOrder(self, n: int) -> List[int]:
        ans = []
        for i in range(1, 10):
            self.solve(i, n, ans)
        return ans




# class Solution:
#     def lexicalOrder(self, n: int) -> List[int]:
#         ans = []
#         for i in range(1, n+1):
#             ans.append(i)
#         ans.sort(key=str)
#         return ans
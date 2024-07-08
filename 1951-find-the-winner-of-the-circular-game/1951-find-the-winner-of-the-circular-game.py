class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        arr = []
        for i in range(n):
            arr.append(i+1)
        i = 0
        while len(arr) > 1:
            i = (i + k - 1) % len(arr)
            arr.pop(i)
        return arr[0]
class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        n = len(arr)
        count = 0
        for i in range(n):
            for j in range(i+1, n):
                a = 0
                for k in range(i, j):
                    a ^= arr[k]
                b = 0
                for k in range(j, n):
                    b ^= arr[k]
                    if a == b:
                        count += 1
        return count
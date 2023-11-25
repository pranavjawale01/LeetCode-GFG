class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        result = ""
        nums = list(range(1, n + 1))

        while n > 0:
            fact = 1
            for i in range(1, n):
                fact *= i

            index = (k - 1) // fact
            k = (k - 1) % fact + 1

            result += str(nums[index])
            nums.pop(index)

            n -= 1

        return result
class Solution:
    def jobScheduling(self, startTime, endTime, profit):
        n = len(startTime)
        memo = [-1] * n

        def getNextIndex(l, currentJobEnd):
            r = n - 1
            result = n + 1

            while l <= r:
                mid = l + (r - l) // 2

                if array[mid][0] >= currentJobEnd:
                    result = mid
                    r = mid - 1
                else:
                    l = mid + 1

            return result

        def solve(i):
            if i >= n:
                return 0

            if memo[i] != -1:
                return memo[i]

            next_index = getNextIndex(i + 1, array[i][1])

            taken = array[i][2] + solve(next_index)
            not_taken = solve(i + 1)

            memo[i] = max(taken, not_taken)
            return memo[i]

        array = list(zip(startTime, endTime, profit))
        array.sort(key=lambda x: x[0])

        return solve(0)


# class Solution:
#     def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
#         jobs = sorted(zip(startTime, endTime, profit), key=lambda x: x[1])
#         dp = [(0, 0)]

#         for start, end, p in jobs:
#             idx = bisect.bisect(dp, (start + 1, 0)) - 1
#             max_profit = max(dp[idx][1] + p, dp[-1][1])
#             dp.append((end, max_profit))

#         return dp[-1][1]
class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        n = len(nums)
        left, right = float('inf'), float('-inf')
        min_heap = []

        for i in range(n):
            heapq.heappush(min_heap, (nums[i][0], i, 0))
            left = min(left, nums[i][0])
            right = max(right, nums[i][0])

        res = [left, right]

        while True:
            min_val, row, col = heapq.heappop(min_heap)
            if right - left < res[1] - res[0]:
                res = [left, right]

            if col + 1 == len(nums[row]):
                break
            
            next_val = nums[row][col + 1]
            heapq.heappush(min_heap, (next_val, row, col + 1))
            right = max(right, next_val)
            left = min_heap[0][0]

        return res
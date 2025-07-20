class Solution:
    def buttonWithLongestTime(self, events: List[List[int]]) -> int:
        ans = events[0][0]
        maxTime = events[0][1]

        for i in range(1, len(events)):
            curr = events[i][1] - events[i - 1][1]
            if curr > maxTime or (curr == maxTime and events[i][0] < ans):
                maxTime = curr
                ans = events[i][0]

        return ans
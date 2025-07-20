class Solution:
    def toMinutes(self, time: str) -> int:
        hours = int(time[:2])
        minutes = int(time[3:])
        return hours * 60 + minutes

    def findMinDifference(self, timePoints: List[str]) -> int:
        if len(timePoints) > 1440:
            return 0

        minutesList = [self.toMinutes(time) for time in timePoints]

        minutesList.sort()

        ans = float('inf')

        for i in range(1, len(minutesList)):
            ans = min(ans, minutesList[i] - minutesList[i - 1])

        circularDiff = 1440 + minutesList[0] - minutesList[-1]
        ans = min(ans, circularDiff)

        return ans
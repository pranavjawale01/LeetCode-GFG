class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        mp = Counter(arr)
        freqCount = [0] * (len(arr) + 1)
        uniqueTypes = len(mp)

        for freq in mp.values():
            freqCount[freq] += 1

        for freq in range(1, len(arr) + 1):
            typesICanDelete = min(k // freq, freqCount[freq])
            k -= (typesICanDelete * freq)
            uniqueTypes -= typesICanDelete

            if k <= freq:
                return uniqueTypes

        return 0
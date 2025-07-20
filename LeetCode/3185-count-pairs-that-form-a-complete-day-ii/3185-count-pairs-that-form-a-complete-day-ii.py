class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:
        mp = {}
        count = 0
        for hour in hours:
            mod = hour % 24
            com = (24 - mod) % 24
            if com in mp:
                count += mp[com]
            if mod in mp:
                mp[mod] += 1
            else:
                mp[mod] = 1
        return count
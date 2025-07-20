class Solution:
    def winningPlayerCount(self, n: int, pick: List[List[int]]) -> int:
        mp = defaultdict(lambda: defaultdict(int))
        for x in pick:
            mp[x[0]][x[1]] += 1
        ans = 0
        for i in range(n):
            require = i + 1
            flag = False
            for x in mp[i].values():
                if x >= require:
                    flag = True
                    break
            if flag:
                ans += 1
        return ans
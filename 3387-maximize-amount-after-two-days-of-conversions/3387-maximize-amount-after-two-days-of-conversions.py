class Solution:
    def maxAmount(self, initialCurrency: str, pairs1: List[List[str]], rates1: List[float], pairs2: List[List[str]], rates2: List[float]) -> float:
        ans = 1.0
        mp1 = defaultdict(list)
        mp2 = defaultdict(list)
        n, m = len(rates1), len(rates2)

        for i in range(n):
            mp1[pairs1[i][0]].append((pairs1[i][1], rates1[i]))
            mp1[pairs1[i][1]].append((pairs1[i][0], 1.0 / rates1[i]))

        for i in range(m):
            mp2[pairs2[i][0]].append((pairs2[i][1], rates2[i]))
            mp2[pairs2[i][1]].append((pairs2[i][0], 1.0 / rates2[i]))

        def solve(mp, start):
            maxAmt = {start: 1.0}
            queue = deque([start])

            while queue:
                curr = queue.popleft()
                currAmt = maxAmt[curr]
                for ne, rt in mp[curr]:
                    amt = currAmt * rt
                    if amt > maxAmt.get(ne, 0.0):
                        maxAmt[ne] = amt
                        queue.append(ne)
            return maxAmt

        d1 = solve(mp1, initialCurrency)
        for currency, amt1 in d1.items():
            d2 = solve(mp2, currency)
            if initialCurrency in d2:
                ans = max(ans, amt1 * d2[initialCurrency])

        return ans
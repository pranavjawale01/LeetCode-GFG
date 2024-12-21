class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        mp = defaultdict(list)
        degree = [0] * n
        for u, v in edges:
            mp[u].append(v)
            mp[v].append(u)
            degree[u] += 1
            degree[v] += 1
        q = deque()
        for i in range(n):
            if degree[i] == 1:
                q.append(i)
        arr = list(map(int, values))
        count = 0
        while q:
            top = q.popleft()
            degree[top] -= 1
            rem = arr[top] % k
            if rem == 0:
                count += 1
                arr[top] = 0
            for x in mp[top]:
                if degree[x] > 0:
                    degree[x] -= 1
                    arr[x] += arr[top]
                    if degree[x] == 1:
                        q.append(x)
        return count if count > 0 else 1
class Solution:
    def floydWarshall(self, arr):
        for via in range(26):
            for i in range(26):
                for j in range(26):
                    arr[i][j] = min(arr[i][j], arr[i][via] + arr[via][j])

    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        arr = [[sys.maxsize for _ in range(26)] for _ in range(26)]
        n = len(original)
        for i in range(n):
            u = ord(original[i]) - ord('a')
            v = ord(changed[i])  - ord('a')
            arr[u][v] = min(cost[i], arr[u][v])

        for i in range(26):
            arr[i][i] = 0
        
        self.floydWarshall(arr)

        n = len(target)

        ans = 0

        for i in range(n):
            u = ord(source[i]) - ord('a')
            v = ord(target[i]) - ord('a')
            if arr[u][v] == sys.maxsize:
                return -1
            ans += arr[u][v]
        
        return ans
class Solution:
    def canTraverseAllPairs(self, nums: List[int]) -> bool:
        def find(x):
            if parent[x] == x:
                return x
            parent[x] = find(parent[x])
            return parent[x]

        def union(x, y):
            x_parent = find(x)
            y_parent = find(y)
            if x_parent != y_parent:
                if size[x_parent] > size[y_parent]:
                    parent[y_parent] = x_parent
                    size[x_parent] += size[y_parent]
                else:
                    parent[x_parent] = y_parent
                    size[y_parent] += size[x_parent]
                return True
            return False

        n = len(nums)
        parent = list(range(n))
        size = [1] * n

        max_val = max(nums)
        first = [-1] * (max_val + 1)

        for i in range(n):
            for prime in range(2, int(nums[i] ** 0.5) + 1):
                if nums[i] % prime == 0:
                    if first[prime] != -1:
                        union(first[prime], i)
                    else:
                        first[prime] = i
                    while nums[i] % prime == 0:
                        nums[i] //= prime

            if nums[i] > 1:
                if first[nums[i]] != -1:
                    union(first[nums[i]], i)
                else:
                    first[nums[i]] = i

        return sum(1 for i in range(n) if find(i) == i) == 1
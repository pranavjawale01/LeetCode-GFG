class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        bankSet = set(bank)
        visited = set()
        que = []

        que.append(startGene)
        visited.add(startGene)

        level = 0

        while que:
            n = len(que)
            while n:
                n -= 1
                curr = que.pop(0)
                if curr == endGene:
                    return level
                for ch in "ACGT":
                    for i in range(len(curr)):
                        neighbour = curr[:i] + ch + curr[i+1:]
                        if neighbour not in visited and neighbour in bankSet:
                            visited.add(neighbour)
                            que.append(neighbour)
            level += 1
        return -1
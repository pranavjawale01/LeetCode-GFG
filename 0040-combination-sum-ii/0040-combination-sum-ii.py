class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        result, current = [], []
        candidates.sort()

        def findSums(candidates: List[int], target: int, start: int, result: List[List[int]], current: List[int]):
            if target == 0:
                result.append(list(current)) 
            for i in range(start, len(candidates)):
                if i > start and candidates[i] == candidates[i - 1]:
                    continue
                if candidates[i] <= target:
                    current.append(candidates[i])
                    findSums(candidates, target - candidates[i], i + 1, result, current)
                    current.pop()

        findSums(candidates, target, 0, result, current)
        return result
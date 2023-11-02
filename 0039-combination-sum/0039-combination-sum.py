class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        candidates.sort()
        
        def findCombination(candidates, target, start, current, result):
            if target == 0:
                result.append(current[:])
                return
            for i in range(start, len(candidates)):
                if candidates[i] > target:
                    break
                current.append(candidates[i])
                findCombination(candidates, target - candidates[i], i, current, result)
                current.pop()
        
        findCombination(candidates, target, 0, [], result)
        return result
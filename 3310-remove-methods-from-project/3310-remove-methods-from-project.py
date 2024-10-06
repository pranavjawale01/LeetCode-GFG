class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        bug = set()
        bug.add(k)
        flag = True
        
        while flag:
            flag = False
            for a, b in invocations:
                if a in bug and b not in bug:
                    bug.add(b)
                    flag = True
        
        for a, b in invocations:
            if a not in bug and b in bug:
                return list(range(n))
        
        return [i for i in range(n) if i not in bug]
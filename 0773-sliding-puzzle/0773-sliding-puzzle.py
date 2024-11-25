class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        start = ''.join(str(num) for row in board for num in row)
        target = "123450"
        
        q = deque([start])
        
        mp = {
            0: [1, 3],
            1: [0, 2, 4],
            2: [1, 5],
            3: [0, 4],
            4: [1, 3, 5],
            5: [2, 4]
        }
        
        vis = set()
        vis.add(start)
        
        level = 0
        while q:
            n = len(q)
            for _ in range(n):
                curr = q.popleft()
                if curr == target:
                    return level
                
                idxOfZero = curr.index('0')
                for swapIdx in mp[idxOfZero]:
                    newState = list(curr)
                    newState[idxOfZero], newState[swapIdx] = newState[swapIdx], newState[idxOfZero]
                    newStateStr = ''.join(newState)
                    
                    if newStateStr not in vis:
                        q.append(newStateStr)
                        vis.add(newStateStr)
            level += 1
        
        return -1
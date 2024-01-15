class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        lost_map = {}
        for i in range(len(matches)):
            lost_map[matches[i][1]] = lost_map.get(matches[i][1], 0) + 1
            
        loss , win = [] , []
        
        for i in range(len(matches)):
            if lost_map.get(matches[i][1], 0) == 1:
                loss.append(matches[i][1])
            if matches[i][0] not in lost_map:
                win.append(matches[i][0])
                lost_map[matches[i][0]] = lost_map.get(matches[i][0], 0) + 2
        
        loss.sort()
        win.sort()
        
        return [win, loss]
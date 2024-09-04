class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        obstacle_set = set()
        for obs in obstacles:
            obstacle_set.add((obs[0], obs[1]))

        x, y = 0, 0
        dx, dy = 0, 1
        max_dist_sq = 0

        for command in commands:
            if command == -1: 
                dx, dy = dy, -dx
            elif command == -2: 
                dx, dy = -dy, dx
            else: 
                for _ in range(command):
                    next_x, next_y = x + dx, y + dy
                    
                    if (next_x, next_y) in obstacle_set:
                        break
                    
                    x, y = next_x, next_y
                    
                    max_dist_sq = max(max_dist_sq, x * x + y * y)

        return max_dist_sq
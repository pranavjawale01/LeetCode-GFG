class Solution:
    def finalPositionOfSnake(self, n: int, commands: List[str]) -> int:
        count = 0
        for command in commands:
            if command == "UP":
                count -= n
            elif command == "DOWN":
                count += n
            elif command == "RIGHT":
                count += 1
            elif command == "LEFT":
                count -= 1
        return count
class Solution:
    def solve(self, rooms: List[List[int]], visited: List[bool], i: int):
        if visited[i]:
            return
        visited[i] = True
        for room in rooms[i]:
            self.solve(rooms, visited, room)

    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        visited = [False] * n
        visited[0] = True
        for room in rooms[0]:
            self.solve(rooms, visited, room)
        for i in range(n):
            if visited[i] is False:
                return False
        return True
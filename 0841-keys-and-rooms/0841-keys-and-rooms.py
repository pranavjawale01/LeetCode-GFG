class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        q = deque()
        for room in rooms[0]:
            q.append(room)
        visited = [False] * n
        visited[0] = True
        while q:
            temp = q.popleft()
            visited[temp] = True
            for room in rooms[temp]:
                if not visited[room]:
                    q.append(room)
        for i in range(n):
            if visited[i] == False:
                return False
        return True

# class Solution:
#     def solve(self, rooms: List[List[int]], visited: List[bool], i: int):
#         if visited[i]:
#             return
#         visited[i] = True
#         for room in rooms[i]:
#             self.solve(rooms, visited, room)

#     def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
#         n = len(rooms)
#         visited = [False] * n
#         visited[0] = True
#         for room in rooms[0]:
#             self.solve(rooms, visited, room)
#         for i in range(n):
#             if visited[i] is False:
#                 return False
#         return True
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        q = deque([start])
        n = len(arr)
        
        while q:
            curr = q.popleft()
            
            if arr[curr] == 0:
                return True
            
            if arr[curr] < 0:
                continue
            
            jump = arr[curr]
            arr[curr] = -arr[curr] 
            
            if curr + jump < n:
                q.append(curr + jump)
            if curr - jump >= 0:
                q.append(curr - jump)
        
        return False




# class Solution:
#     def canReach(self, arr: List[int], start: int) -> bool:
#         if start < 0 or start >= len(arr):
#             return False
#         if arr[start] < 0:
#             return False
#         if arr[start] == 0:
#             return True
#         jump = arr[start]
#         arr[start] = -arr[start]
#         return self.canReach(arr, start + jump) or self.canReach(arr, start - jump)
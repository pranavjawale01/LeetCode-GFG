class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        adj = defaultdict(list)
        for i, mgr in enumerate(manager):
            if mgr != -1:
                adj[mgr].append(i)
        
        return self.bfs(headID, adj, informTime)
    
    def bfs(self, head_id, adj, informTime):
        if head_id not in adj:
            return 0
        max_time = 0
        queue = deque([(head_id, 0)])
        while queue:
            head, time = queue.popleft()
            max_time = max(max_time, time)
            for sub in adj[head]:
                queue.append((sub, time + informTime[head]))
        return max_time




# class Solution:
#     def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
#         adj = defaultdict(list)
#         for i, mgr in enumerate(manager):
#             if mgr != -1:
#                 adj[mgr].append(i)
        
#         return self.dfs(headID, adj, informTime)
    
#     def dfs(self, head_id, adj, informTime):
#         if head_id not in adj:
#             return 0
#         max_time = 0
#         for sub in adj[head_id]:
#             max_time = max(max_time, self.dfs(sub, adj, informTime))
#         return max_time + informTime[head_id]
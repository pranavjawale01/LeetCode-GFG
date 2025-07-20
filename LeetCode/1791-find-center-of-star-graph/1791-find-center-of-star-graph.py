class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        a = edges[0][0]
        b = edges[0][1]

        if a == edges[1][0] or a == edges[1][1]:
            return a
        
        return b





# class Solution:
#     def findCenter(self, edges: List[List[int]]) -> int:
#         mp = defaultdict(int)
#         for edge in edges:
#             mp[edge[0]] += 1
#             mp[edge[1]] += 1
#         n = len(edges)
#         for key, value in mp.items():
#             if value == n:
#                 return key
#         return -1
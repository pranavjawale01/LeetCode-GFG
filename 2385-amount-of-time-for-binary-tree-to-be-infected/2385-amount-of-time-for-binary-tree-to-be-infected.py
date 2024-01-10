# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def makeGraph(self, adj, parent, curr):
        if not curr:
            return
        if parent != -1:
            adj[curr.val].append(parent)
        if curr.left:
            adj[curr.val].append(curr.left.val)
        if curr.right:
            adj[curr.val].append(curr.right.val)
        self.makeGraph(adj, curr.val, curr.left)
        self.makeGraph(adj, curr.val, curr.right)
    
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        adj = defaultdict(list)
        self.makeGraph(adj, -1, root)
        
        que = deque()
        visited = set()
        
        que.append(start)
        visited.add(start)
        
        minutes = 0
        
        while que:
            n = len(que)
            for _ in range(n):
                curr = que.popleft()
                for ngbr in adj[curr]:
                    if ngbr not in visited:
                        que.append(ngbr)
                        visited.add(ngbr)
            minutes += 1
        
        return minutes - 1
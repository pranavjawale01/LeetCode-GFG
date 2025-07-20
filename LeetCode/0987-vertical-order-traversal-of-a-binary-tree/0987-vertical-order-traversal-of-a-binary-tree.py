# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        nodes = defaultdict(lambda: defaultdict(list))
        queue = deque([(root, 0, 0)])
        
        while queue:
            node, col, row = queue.popleft()
            heapq.heappush(nodes[col][row], node.val)
            
            if node.left:
                queue.append((node.left, col - 1, row + 1))
            if node.right:
                queue.append((node.right, col + 1, row + 1))
        
        result = []
        for col in sorted(nodes):
            col_nodes = []
            for row in sorted(nodes[col]):
                while nodes[col][row]:
                    col_nodes.append(heapq.heappop(nodes[col][row]))
            result.append(col_nodes)
        
        return result
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        output = []
        if root is None:
            return output;
        
        queue = deque([root])
        
        while queue:
            size = len(queue)
            currLevel = []
            
            while size:
                current = queue.popleft()
                currLevel.append(current.val)
                
                if current.left:
                    queue.append(current.left)
                if current.right:
                    queue.append(current.right)
                size -= 1
            output.append(currLevel)
            
        return output
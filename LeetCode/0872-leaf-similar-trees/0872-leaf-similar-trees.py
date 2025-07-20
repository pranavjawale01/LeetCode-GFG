# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def dfs(root, leaves):
            if root is not None:
                if root.left is None and root.right is None:
                    leaves.append(root.val)
                dfs(root.left, leaves)
                dfs(root.right, leaves)
        
        leaves1, leaves2 = [], []
        dfs(root1, leaves1)
        dfs(root2, leaves2)
        
        return leaves1 == leaves2
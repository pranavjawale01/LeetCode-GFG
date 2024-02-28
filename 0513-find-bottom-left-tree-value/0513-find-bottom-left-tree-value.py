# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        maxDepth = -1
        value = 0
        def solve(root: Optional[TreeNode], depth : int):
            nonlocal maxDepth, value
            if not root:
                return
            if depth > maxDepth:
                maxDepth = depth
                value = root.val
            solve(root.left, depth + 1)
            solve(root.right, depth + 1)
        solve(root, 0)
        return value
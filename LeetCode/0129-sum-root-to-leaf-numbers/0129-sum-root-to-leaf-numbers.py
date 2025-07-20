# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root: Optional[TreeNode], ans: int) -> int:
        if not root:
            return 0
        ans = ans * 10 + root.val
        if not root.left and not root.right:
            return ans
        return self.solve(root.left, ans) + self.solve(root.right, ans)
        
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        return self.solve(root, 0)
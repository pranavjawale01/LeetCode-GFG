# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, l, r, lvl):
        if not l or not r:
            return
        if lvl % 2 == 1:
            l.val, r.val = r.val, l.val
        self.solve(l.left, r.right, lvl + 1)
        self.solve(l.right, r.left, lvl + 1)

    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.solve(root.left, root.right, 1)
        return root
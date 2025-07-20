# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def solve(self, root: Optional[TreeNode], isLeft: bool) -> int:
        if not root:
            return 0
        if not root.left and not root.right:
            if isLeft:
                return root.val
        return self.solve(root.left, True) + self.solve(root.right, False)

    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        return self.solve(root, False)

# class Solution:
#     def solve(self, root: Optional[TreeNode], parent: Optional[TreeNode]) -> int:
#         if not root:
#             return 0
#         if not root.left and not root.right:
#             if parent and parent.left is root:
#                 return root.val
#         return self.solve(root.left, root) + self.solve(root.right, root)

#     def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
#         return self.solve(root, None)
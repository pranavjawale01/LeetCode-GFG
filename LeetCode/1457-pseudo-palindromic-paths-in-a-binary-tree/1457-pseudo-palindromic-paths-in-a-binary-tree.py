# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def pseudoPalindromicPaths(self, root: Optional[TreeNode]) -> int:
        self.result = 0
        self.solve(root, 0)
        return self.result

    def solve(self, root: Optional[TreeNode], count: int) -> None:
        if not root:
            return

        count ^= 1 << root.val

        if not root.left and not root.right:
            if count & (count - 1) == 0:
                self.result += 1

        self.solve(root.left, count)
        self.solve(root.right, count)
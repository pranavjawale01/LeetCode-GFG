# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        result = [float('-inf')]

        def solve(root: Optional[TreeNode], result: List[int]) -> int:
            if not root:
                return 0
            a = solve(root.left, result)
            b = solve(root.right, result)
            result[0] = max(result[0], a + b)
            return 1 + max(a, b)

        solve(root, result)
        return result[0]
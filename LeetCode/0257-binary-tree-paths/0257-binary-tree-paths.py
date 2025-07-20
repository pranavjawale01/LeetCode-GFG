# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans = []

    def solve(self, root: Optional[TreeNode], path: str) -> None:
        if not root:
            return
        if not root.left and not root.right:
            path += str(root.val)
            self.ans.append(path)
            return
        path += str(root.val) + "->"
        self.solve(root.left, path)
        self.solve(root.right, path)

    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        self.solve(root, "")
        return self.ans
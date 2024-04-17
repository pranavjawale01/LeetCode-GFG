# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans = ""

    def solve(self, root: Optional[TreeNode], temp : str):
        if not root:
            return
        temp = chr(root.val + ord('a')) + temp
        if not root.left and not root.right:
            if not self.ans or self.ans > temp:
                self.ans = temp
        self.solve(root.left, temp)
        self.solve(root.right, temp)

    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        self.solve(root, "")
        return self.ans
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    totalSum : int = 0
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        if root == None:
            return 0
        if root.val >= low and root.val <= high:
            self.totalSum += root.val
        self.rangeSumBST(root.left, low, high)
        self.rangeSumBST(root.right, low, high)
        
        return self.totalSum
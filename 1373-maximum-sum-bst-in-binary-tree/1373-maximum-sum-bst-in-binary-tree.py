# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.res = 0

    def solve(self, root):
        if not root:
            return (float('inf'), float('-inf'), 0)
        
        left = self.solve(root.left)
        right = self.solve(root.right)
        
        if left[1] >= root.val or right[0] <= root.val:
            return (float('-inf'), float('inf'), 0)
        
        sum_val = left[2] + right[2] + root.val
        self.res = max(self.res, sum_val)
        
        return (min(root.val, left[0]), max(root.val, right[1]), sum_val)

    def maxSumBST(self, root: Optional[TreeNode]) -> int:
        self.solve(root)
        return max(0, self.res)
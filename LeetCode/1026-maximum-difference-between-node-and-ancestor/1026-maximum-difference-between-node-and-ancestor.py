# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        
        def maxDiff (root : Optional[TreeNode], minV: int, maxV: int) -> int:
            if root is None:
                return abs(maxV - minV)
            maxV = max(maxV, root.val)
            minV = min(minV, root.val)
            l , r = maxDiff(root.left, minV, maxV) , maxDiff(root.right, minV, maxV)
            return max(l, r)
        
        return maxDiff(root, root.val, root.val)
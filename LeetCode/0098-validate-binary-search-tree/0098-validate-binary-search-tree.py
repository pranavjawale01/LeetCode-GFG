# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.isValidHelper(root, float('-inf'), float('inf'))
    
    def isValidHelper(self, root: Optional[TreeNode], minVal, maxVal) -> bool:
        if root is None:
            return True
        if not (minVal < root.val < maxVal):
            return False
        return (self.isValidHelper(root.left, minVal, root.val) and 
                self.isValidHelper(root.right, root.val, maxVal))
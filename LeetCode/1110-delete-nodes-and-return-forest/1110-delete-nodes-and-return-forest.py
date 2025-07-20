# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteHelper(self, root: TreeNode, toDelete: Set[int], result: List[TreeNode]) -> TreeNode:
        if root is None:
            return None
        
        root.left = self.deleteHelper(root.left, toDelete, result)
        root.right = self.deleteHelper(root.right, toDelete, result)
        
        if root.val in toDelete:
            if root.left:
                result.append(root.left)
            if root.right:
                result.append(root.right)
            return None
        else:
            return root

    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        result = []
        toDelete = set(to_delete)
        
        self.deleteHelper(root, toDelete, result)
        
        if root.val not in toDelete:
            result.append(root)
        
        return result
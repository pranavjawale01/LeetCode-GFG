# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        self.inorderTraversalRecursive(root, result)
        return result

    def inorderTraversalRecursive(self, node: Optional[TreeNode], result: List[int]) -> None:
        if node is None:
            return
        self.inorderTraversalRecursive(node.left, result)
        result.append(node.val)
        self.inorderTraversalRecursive(node.right, result)
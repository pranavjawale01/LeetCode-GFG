# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if depth == 1:
            newRoot = TreeNode(val, root, None)
            return newRoot
        self.DFS(root, val, 1, depth)
        return root
    
    def DFS(self, node, val, currDepth, targetDepth):
        if node != None:
            if currDepth == targetDepth-1:
                newNodeLeft = TreeNode(val, node.left, None)
                newNodeRight = TreeNode(val, None, node.right)
                node.left = newNodeLeft
                node.right = newNodeRight
            else:
                self.DFS(node.left, val, currDepth+1, targetDepth)
                self.DFS(node.right, val, currDepth+1, targetDepth)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def constructTree(self, preorder: List[int], inorder: List[int], start: int, end: int, index: List[int]) -> Optional[TreeNode]:
        if start > end:
            return None
        rootVal = preorder[index[0]]
        i = start
        while i <= end:
            if rootVal == inorder[i]:
                break
            i += 1
        index[0] += 1
        root = TreeNode(rootVal)
        root.left = self.constructTree(preorder, inorder, start, i - 1, index)
        root.right = self.constructTree(preorder, inorder, i + 1, end, index)
        return root

    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        index = [0]
        return self.constructTree(preorder, inorder, 0, len(preorder) - 1, index)
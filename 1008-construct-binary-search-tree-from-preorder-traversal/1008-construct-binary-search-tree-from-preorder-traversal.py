# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        def build_tree(start, end):
            if start > end:
                return None

            root = TreeNode(preorder[start])
            idx = start + 1

            while idx <= end and preorder[idx] < preorder[start]:
                idx += 1

            root.left = build_tree(start + 1, idx - 1)
            root.right = build_tree(idx, end)

            return root

        return build_tree(0, len(preorder) - 1)
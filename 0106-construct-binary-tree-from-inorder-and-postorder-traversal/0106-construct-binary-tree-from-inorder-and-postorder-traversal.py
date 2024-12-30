# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        def build(in_start, in_end, post_index):
            if in_start > in_end:
                return None

            val = postorder[post_index[0]]
            post_index[0] -= 1
            root = TreeNode(val)

            in_index = inorder_map[val]
            root.right = build(in_index + 1, in_end, post_index)
            root.left = build(in_start, in_index - 1, post_index)

            return root

        inorder_map = {val: idx for idx, val in enumerate(inorder)}
        return build(0, len(inorder) - 1, [len(postorder) - 1])
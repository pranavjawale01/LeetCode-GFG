# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorder(self, root: TreeNode):
        if not root:
            return
        self.inorder(root.left)
        self.arr.append(root.val)
        self.inorder(root.right)

    def solve(self, low: int, high: int) -> TreeNode:
        if low > high:
            return
        mid = low + (high - low) // 2
        root = TreeNode(self.arr[mid])
        root.left = self.solve(low, mid - 1)
        root.right = self.solve(mid + 1, high)
        return root

    def balanceBST(self, root: TreeNode) -> TreeNode:
        self.arr = []
        self.inorder(root)
        return self.solve(0, len(self.arr)-1)
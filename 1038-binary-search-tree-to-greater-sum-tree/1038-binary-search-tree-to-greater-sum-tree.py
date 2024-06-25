# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.sum = 0

    def revinorder(self, root: TreeNode):
        if not root:
            return
        self.revinorder(root.right)
        self.sum += root.val
        root.val = self.sum
        self.revinorder(root.left)

    def bstToGst(self, root: TreeNode) -> TreeNode:
        self.sum = 0
        self.revinorder(root)
        return root




# # Definition for a binary tree node.
# # class TreeNode:
# #     def __init__(self, val=0, left=None, right=None):
# #         self.val = val
# #         self.left = left
# #         self.right = right
# class Solution:
#     def __init__(self):
#         self.temp = []
    
#     def inorder(self, root: TreeNode):
#         if root is None:
#             return
#         self.inorder(root.left)
#         self.temp.append(root.val)
#         self.inorder(root.right)
    
#     def bs(self, val: int, ans: list[int]) -> int:
#         low, high = 0, len(ans) - 1
#         while low <= high:
#             mid = (low + high) // 2
#             if self.temp[mid] == val:
#                 return ans[mid]
#             elif self.temp[mid] > val:
#                 high = mid - 1
#             else:
#                 low = mid + 1
#         return val
    
#     def solve(self, root: TreeNode, ans: list[int]):
#         if root is None:
#             return
#         root.val = self.bs(root.val, ans)
#         self.solve(root.left, ans)
#         self.solve(root.right, ans)
    
#     def bstToGst(self, root: TreeNode) -> TreeNode:
#         self.inorder(root)
#         n = len(self.temp)
#         ans = [0] * n
#         ans[n - 1] = self.temp[n - 1]
#         for i in range(n - 2, -1, -1):
#             ans[i] = self.temp[i] + ans[i + 1]
#         self.solve(root, ans)
#         return root
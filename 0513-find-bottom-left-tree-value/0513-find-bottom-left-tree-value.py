# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        q = deque([root])
        value = 0
        while q:
            n = len(q)
            while n:
                temp = q.popleft()
                value = temp.val
                if temp.right:
                    q.append(temp.right)
                if temp.left:
                    q.append(temp.left)
                n -= 1
        return value

# class Solution:
#     def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
#         q = deque([root])
#         value = 0
#         while q:
#             temp = q.popleft()
#             value = temp.val
#             if temp.right:
#                 q.append(temp.right)
#             if temp.left:
#                 q.append(temp.left)
#         return value

# # Definition for a binary tree node.
# # class TreeNode:
# #     def __init__(self, val=0, left=None, right=None):
# #         self.val = val
# #         self.left = left
# #         self.right = right
# class Solution:
#     def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
#         maxDepth = -1
#         value = 0
#         def solve(root: Optional[TreeNode], depth : int):
#             nonlocal maxDepth, value
#             if not root:
#                 return
#             if depth > maxDepth:
#                 maxDepth = depth
#                 value = root.val
#             solve(root.left, depth + 1)
#             solve(root.right, depth + 1)
#         solve(root, 0)
#         return value
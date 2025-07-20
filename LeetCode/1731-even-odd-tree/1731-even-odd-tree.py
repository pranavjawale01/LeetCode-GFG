# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        def solve(root, level, level_prev):
            if not root:
                return True

            if (level % 2 == 0 and root.val % 2 == 0) or (level % 2 != 0 and root.val % 2 != 0):
                return False

            if level >= len(level_prev):
                level_prev.append(root.val)
            else:
                if (level % 2 == 0 and root.val <= level_prev[level]) or (level % 2 != 0 and root.val >= level_prev[level]):
                    return False
                level_prev[level] = root.val

            return solve(root.left, level + 1, level_prev) and solve(root.right, level + 1, level_prev)

        return solve(root, 0, [])
        
# class Solution:
#     def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
#         q = deque([root])
#         even_level = True
#         while q:
#             n = len(q)
#             prev = float('-inf') if even_level else float('inf')

#             while n > 0:
#                 n -= 1
#                 temp = q.popleft()
#                 if temp.left:
#                     q.append(temp.left)
#                 if temp.right:
#                     q.append(temp.right)
#                 if even_level and (temp.val % 2 == 0 or temp.val <= prev):
#                     return False
#                 if not even_level and (temp.val % 2 != 0 or temp.val >= prev):
#                     return False
#                 prev = temp.val
            
#             even_level = not even_level
        
#         return True
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque

class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return root
        
        q = deque([root])
        level_sum = []

        while q:
            curr_lvl_sum = 0
            n = len(q)
            for _ in range(n):
                curr = q.popleft()
                curr_lvl_sum += curr.val
                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)
            level_sum.append(curr_lvl_sum)

        q.append(root)
        root.val = 0
        level = 1

        while q:
            n = len(q)
            for _ in range(n):
                curr = q.popleft()
                sibling_sum = (curr.left.val if curr.left else 0) + (curr.right.val if curr.right else 0)

                if curr.left:
                    curr.left.val = level_sum[level] - sibling_sum
                    q.append(curr.left)
                if curr.right:
                    curr.right.val = level_sum[level] - sibling_sum
                    q.append(curr.right)
            level += 1

        return root
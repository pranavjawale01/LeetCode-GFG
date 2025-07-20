# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        q = deque([root])
        even_level = True
        while q:
            n = len(q)
            prev = float('-inf') if even_level else float('inf')

            while n > 0:
                n -= 1
                temp = q.popleft()
                if temp.left:
                    q.append(temp.left)
                if temp.right:
                    q.append(temp.right)
                if even_level and (temp.val % 2 == 0 or temp.val <= prev):
                    return False
                if not even_level and (temp.val % 2 != 0 or temp.val >= prev):
                    return False
                prev = temp.val
            
            even_level = not even_level
        
        return True
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and not q:
            return True
        if not p or not q:
            return False
        a = deque([p])
        b = deque([q])

        while a and b:
            temp1 = a.popleft()
            temp2 = b.popleft()

            if temp1.val != temp2.val:
                return False

            if temp1.left and temp2.left:
                a.append(temp1.left)
                b.append(temp2.left)
            elif temp1.left or temp2.left:
                return False
            
            if temp1.right and temp2.right:
                a.append(temp1.right)
                b.append(temp2.right)
            elif temp1.right or temp2.right:
                return False
        
        return True

# # Definition for a binary tree node.
# # class TreeNode:
# #     def __init__(self, val=0, left=None, right=None):
# #         self.val = val
# #         self.left = left
# #         self.right = right
# class Solution:
#     def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
#         if p is None and q is None:
#             return True
#         if p is None or q is None:
#             return False
#         if p.val == q.val:
#             return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
#         return False
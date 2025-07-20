"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        if not root:
            return []
        
        stack = [root]
        ans = []
        
        while stack:
            temp = stack.pop()
            ans.append(temp.val)
            stack.extend(temp.children)
        
        return ans[::-1]






# class Solution:
#     def __init__(self):
#         self.ans = []

#     def solve(self, root: 'Node'):
#         if not root:
#             return
#         for child in root.children:
#             self.solve(child)
#         self.ans.append(root.val)

#     def postorder(self, root: 'Node') -> List[int]:
#         self.solve(root)
#         return self.ans
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        mp = {}
        childSet = set()
        
        for x in descriptions:
            p, c, l = x
            if p not in mp:
                mp[p] = TreeNode(p)
            if c not in mp:
                mp[c] = TreeNode(c)
                
            if l == 1:
                mp[p].left = mp[c]
            else:
                mp[p].right = mp[c]
                
            childSet.add(c)
            
        for x in descriptions:
            p = x[0]
            if p not in childSet:
                return mp[p]
                
        return None
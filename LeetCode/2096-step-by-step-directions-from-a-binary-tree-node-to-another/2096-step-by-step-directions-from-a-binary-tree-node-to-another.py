# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def findPath(self, root: Optional[TreeNode], target: int, path: List[str]) -> bool:
        if not root:
            return False
        if root.val == target:
            return True
        path.append('L')
        if self.findPath(root.left, target, path):
            return True
        path.pop()
        path.append('R')
        if self.findPath(root.right, target, path):
            return True
        path.pop()
        return False

    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        rootToSrc = []
        rootToDes = []
        self.findPath(root, startValue, rootToSrc)
        self.findPath(root, destValue, rootToDes)

        i = 0
        while i < len(rootToSrc) and i < len(rootToDes) and rootToSrc[i] == rootToDes[i]:
            i += 1
        
        result = 'U' * (len(rootToSrc) - i)
        result += ''.join(rootToDes[i:])
        return result





# class Solution:
#     def lowestCommonAncestor(self, root: Optional[TreeNode], src: int, dest: int) -> Optional[TreeNode]:
#         if not root:
#             return None
#         if root.val == src or root.val == dest:
#             return root
#         l = self.lowestCommonAncestor(root.left, src, dest)
#         r = self.lowestCommonAncestor(root.right, src, dest)
#         if l and r:
#             return root
#         return l if l else r

#     def findPath(self, root: Optional[TreeNode], target: int, path: List[str]) -> bool:
#         if not root:
#             return False
#         if root.val == target:
#             return True
#         path.append("L")
#         if self.findPath(root.left, target, path):
#             return True
#         path.pop()
#         path.append("R")
#         if self.findPath(root.right, target, path):
#             return True
#         path.pop()
#         return False

#     def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
#         LCA = self.lowestCommonAncestor(root, startValue, destValue)
#         lcaToSrc, lcaToDes = [], []
#         self.findPath(LCA, startValue, lcaToSrc)
#         self.findPath(LCA, destValue, lcaToDes)
#         result = "U" * len(lcaToSrc)
#         result += "".join(lcaToDes)
#         return result
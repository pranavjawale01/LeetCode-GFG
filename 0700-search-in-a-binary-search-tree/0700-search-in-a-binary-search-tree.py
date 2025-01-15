# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        ans = [None]
        
        def solve(rt):
            if not rt:
                return
            if rt.val == val:
                ans[0] = rt
                return
            solve(rt.left)
            solve(rt.right)
        
        solve(root)
        return ans[0]
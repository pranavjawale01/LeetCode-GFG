# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root, curr, target, mp) -> int:
        if not root:
            return 0
        curr += root.val
        count = 0
        if curr - target in mp:
            count = mp[curr - target]
        if curr in mp:
            mp[curr] += 1
        else:
            mp[curr] = 1
        count += self.solve(root.left, curr, target, mp)
        count += self.solve(root.right,curr, target, mp)
        mp[curr] -= 1
        return count

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        mp = {}
        mp[0] = 1
        return self.solve(root, 0, targetSum, mp)
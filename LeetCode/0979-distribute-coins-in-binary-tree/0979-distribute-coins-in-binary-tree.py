# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root, moves):
        if root is None:
            return 0
        
        l = self.solve(root.left, moves)
        r = self.solve(root.right, moves)
        
        total_extra_candies = (l + r + root.val) - 1
        moves[0] += abs(l) + abs(r)
        
        return total_extra_candies
        
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        moves = [0]
        if not root.left and not root.right:
            return 0
        self.solve(root, moves)
        return moves[0]
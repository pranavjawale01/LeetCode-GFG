# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans = []

    def solve(self, root: Optional[TreeNode], targetSum: int, path: List[int]) -> None:
        if not root:
            return

        path.append(root.val)
        targetSum -= root.val

        if not root.left and not root.right:
            if targetSum == 0:
                self.ans.append(list(path))
        else:
            self.solve(root.left, targetSum, path)
            self.solve(root.right, targetSum, path)

        path.pop()

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        self.solve(root, targetSum, [])
        return self.ans
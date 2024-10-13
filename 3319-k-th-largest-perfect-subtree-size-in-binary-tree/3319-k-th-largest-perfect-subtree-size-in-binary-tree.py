# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.arr = []

    def solveTree(self, root):
        if not root:
            return True, (0, 0)
        left = self.solveTree(root.left)
        right = self.solveTree(root.right)
        leftBal, (leftHt, leftSz) = left
        rightBal, (rightHt, rightSz) = right
        if leftBal and rightBal and leftHt == rightHt:
            length = leftSz + rightSz + 1
            height = leftHt + 1
            self.arr.append(length)
            return True, (height, length)
        return False, (0, 0)

    def kthLargestPerfectSubtree(self, root: Optional[TreeNode], k: int) -> int:
        self.solveTree(root)
        self.arr.sort(reverse=True)
        if len(self.arr) >= k:
            return self.arr[k - 1]
        return -1
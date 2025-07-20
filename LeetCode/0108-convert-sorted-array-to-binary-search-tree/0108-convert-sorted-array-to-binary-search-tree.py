# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recursive(self, nums: List[int], low: int, high: int) -> Optional[TreeNode]:
        if low <= high:
            mid = low + (high - low) // 2
            root = TreeNode(nums[mid])
            root.left = self.recursive(nums, low, mid - 1)
            root.right = self.recursive(nums, mid + 1, high)
            return root
        return None

    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        return self.recursive(nums, 0, len(nums) - 1)
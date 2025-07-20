# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        queue = deque([(root, 0)])
        max_width = 0

        while queue:
            size = len(queue)
            start = queue[0][1]
            end = queue[-1][1]
            max_width = max(max_width, end - start + 1)

            for _ in range(size):
                node, index = queue.popleft()
                normalized_index = index - start

                if node.left:
                    queue.append((node.left, 2 * normalized_index + 1))
                if node.right:
                    queue.append((node.right, 2 * normalized_index + 2))

        return max_width
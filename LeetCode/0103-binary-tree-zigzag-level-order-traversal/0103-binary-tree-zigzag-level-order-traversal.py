# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result = []
        if not root:
            return result
        q = deque([root])
        left_to_right = True
        while q:
            n = len(q)
            temp = [0] * n
            for i in range(n):
                current = q.popleft()
                index = i if left_to_right else n - 1 - i
                temp[index] = current.val
                if current.left:
                    q.append(current.left)
                if current.right:
                    q.append(current.right)
            result.append(temp)
            left_to_right = not left_to_right
        return result
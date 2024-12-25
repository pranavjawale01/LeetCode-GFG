# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        q = deque()
        q.append(root)
        ans = []
        if not root:
            return ans
        ans.append(root.val)
        while q:
            n = len(q)
            flag = False
            maxVal = 0
            while n:
                n -= 1
                temp = q.popleft()
                if temp.left:
                    if not flag:
                        maxVal = temp.left.val
                    flag = True
                    q.append(temp.left)
                    maxVal = max(maxVal, temp.left.val)
                if temp.right:
                    if not flag:
                        maxVal = temp.right.val
                    flag = True
                    q.append(temp.right)
                    maxVal = max(maxVal, temp.right.val)
            if flag:
                ans.append(maxVal)
        return ans
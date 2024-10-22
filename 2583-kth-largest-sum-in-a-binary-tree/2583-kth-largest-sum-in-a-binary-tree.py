# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        q = deque([root])
        pq = []

        while q:
            level_sum = 0
            n = len(q)
            for _ in range(n):
                node = q.popleft()
                level_sum += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            heapq.heappush(pq, -level_sum)

        if len(pq) < k:
            return -1
        
        for _ in range(k - 1):
            heapq.heappop(pq)
        
        return -pq[0]
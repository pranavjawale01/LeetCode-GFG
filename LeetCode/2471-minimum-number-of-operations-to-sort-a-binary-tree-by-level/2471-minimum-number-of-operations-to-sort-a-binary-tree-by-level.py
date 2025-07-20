# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countMinSwap(self, arr):
        swaps = 0
        sorted_arr = sorted(arr)
        index_map = {value: idx for idx, value in enumerate(arr)}
        for i in range(len(arr)):
            if arr[i] == sorted_arr[i]:
                continue
            curr_idx = index_map[sorted_arr[i]]
            index_map[arr[i]] = curr_idx
            index_map[arr[curr_idx]] = i
            arr[i], arr[curr_idx] = arr[curr_idx], arr[i]
            swaps += 1
        return swaps

    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        q = deque([root])
        ans = 0
        while q:
            n = len(q)
            arr = []
            for _ in range(n):
                temp = q.popleft()
                arr.append(temp.val)
                if temp.left:
                    q.append(temp.left)
                if temp.right:
                    q.append(temp.right)
            ans += self.countMinSwap(arr)
        return ans
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.level = {}
        self.height = {}
        self.levelMaxHt = {}
        self.levelSecondMaxHt = {}

    def findHeight(self, root: Optional['TreeNode'], l: int) -> int:
        if not root:
            return 0

        self.level[root.val] = l
        self.height[root.val] = max(self.findHeight(root.left, l + 1), self.findHeight(root.right, l + 1)) + 1

        if l not in self.levelMaxHt or self.levelMaxHt[l] < self.height[root.val]:
            self.levelSecondMaxHt[l] = self.levelMaxHt.get(l, 0)
            self.levelMaxHt[l] = self.height[root.val]
        elif self.levelSecondMaxHt.get(l, 0) < self.height[root.val]:
            self.levelSecondMaxHt[l] = self.height[root.val]

        return self.height[root.val]

    def treeQueries(self, root: Optional['TreeNode'], queries: List[int]) -> List[int]:
        self.findHeight(root, 0)
        
        result = []
        for node in queries:
            L = self.level[node]
            tempResult = L + (self.levelSecondMaxHt[L] if self.levelMaxHt[L] == self.height[node] else self.levelMaxHt[L]) - 1
            result.append(tempResult)

        return result
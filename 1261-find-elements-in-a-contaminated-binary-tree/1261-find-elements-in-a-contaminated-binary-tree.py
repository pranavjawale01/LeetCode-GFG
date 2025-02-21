# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class FindElements:
      
    def dfs(self, root, x):
        if not root:
            return
        root.val = x
        self.st.add(x)
        self.dfs(root.left, 2 * x + 1)
        self.dfs(root.right, 2 * x + 2)

    def __init__(self, root: Optional[TreeNode]):
        self.st = set()
        if root:
            self.dfs(root, 0)

    def find(self, target: int) -> bool:
        return target in self.st


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
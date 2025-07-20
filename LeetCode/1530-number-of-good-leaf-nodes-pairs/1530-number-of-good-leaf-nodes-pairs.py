# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root: Optional[TreeNode], distance: int) -> List[int]:
        if not root:
            return []
        if not root.left and not root.right:
            return [1]
        
        left = self.solve(root.left, distance)
        right = self.solve(root.right, distance)

        for l in left:
            for r in right:
                if l != 0 and r != 0 and l + r <= distance:
                    self.goodLeaf += 1

        curr = []
        for l in left:
            if l != 0 and l + 1 <= distance:
                curr.append(l + 1)
        for r in right:
            if r != 0 and r + 1 <= distance:
                curr.append(r + 1)
                
        return curr

    def countPairs(self, root: Optional[TreeNode], distance: int) -> int:
        self.goodLeaf = 0
        self.solve(root, distance)
        return self.goodLeaf






# class Solution:
#     def makeGraph(self, root: TreeNode, prev: TreeNode, mp, st):
#         if not root:
#             return
#         if not root.left and not root.right:
#             st.add(root)
#         if prev:
#             mp[root].append(prev)
#             mp[prev].append(root)
#         self.makeGraph(root.left, root, mp, st)
#         self.makeGraph(root.right, root, mp, st)

#     def countPairs(self, root: TreeNode, distance: int) -> int:
#         mp = defaultdict(list)
#         st = set()
#         self.makeGraph(root, None, mp, st)
#         count = 0
#         for leaf in st:
#             q = deque()
#             vis = set()
#             q.append(leaf)
#             vis.add(leaf)
#             for i in range(distance + 1):
#                 size = len(q)
#                 while size > 0:
#                     size -= 1
#                     curr = q.popleft()
#                     if curr != leaf and curr in st:
#                         count += 1
#                     for x in mp[curr]:
#                         if x not in vis:
#                             q.append(x)
#                             vis.add(x)

#         return count // 2
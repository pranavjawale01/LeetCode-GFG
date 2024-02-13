"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    mp = defaultdict()

    def dfs(self, node: 'Node', clone_node: 'Node') -> None:
        for n in node.neighbors:
            if n not in self.mp:
                self.mp[n] = Node(n.val)
                self.dfs(n, self.mp[n])
            clone_node.neighbors.append(self.mp[n])

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        clone_node = Node(node.val)
        self.mp[node] = clone_node
        self.dfs(node, clone_node)
        return clone_node
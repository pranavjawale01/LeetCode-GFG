# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildGraph(self, node: Optional[TreeNode], parent: Optional[TreeNode], graph: defaultdict) -> None:
        if not node:
            return
        if parent:
            graph[node.val].append(parent.val)
            graph[parent.val].append(node.val)
        self.buildGraph(node.left, node, graph)
        self.buildGraph(node.right, node, graph)

    def bfs(self, target: int, k: int, graph: defaultdict) -> List[int]:
        result = []
        visited = defaultdict(bool)
        queue = deque([target])
        visited[target] = True

        level = 0
        while queue:
            if level == k:
                return list(queue)
            for _ in range(len(queue)):
                node = queue.popleft()
                for neighbor in graph[node]:
                    if not visited[neighbor]:
                        visited[neighbor] = True
                        queue.append(neighbor)
            level += 1

        return result

    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        graph = defaultdict(list)
        self.buildGraph(root, None, graph)
        return self.bfs(target.val, k, graph)
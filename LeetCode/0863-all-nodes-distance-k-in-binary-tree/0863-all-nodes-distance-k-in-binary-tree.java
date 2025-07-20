/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {    
    private void buildGraph(TreeNode node, TreeNode parent, Map<Integer, List<Integer>> graph) {
        if (node == null) {
            return;
        }
        if (parent != null) {
            graph.computeIfAbsent(node.val, k -> new ArrayList<>()).add(parent.val);
            graph.computeIfAbsent(parent.val, k -> new ArrayList<>()).add(node.val);
        }
        buildGraph(node.left, node, graph);
        buildGraph(node.right, node, graph);
    }
    
    private List<Integer> bfs(int target, int k, Map<Integer, List<Integer>> graph) {
        List<Integer> result = new ArrayList<>();
        Map<Integer, Boolean> visited = new HashMap<>();
        Queue<Integer> queue = new LinkedList<>();
        queue.add(target);
        visited.put(target, true);
        
        int level = 0;
        while (!queue.isEmpty()) {
            if (level == k) {
                while (!queue.isEmpty()) {
                    result.add(queue.poll());
                }
                break;
            }
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int node = queue.poll();
                for (int neighbor : graph.getOrDefault(node, Collections.emptyList())) {
                    if (!visited.getOrDefault(neighbor, false)) {
                        visited.put(neighbor, true);
                        queue.add(neighbor);
                    }
                }
            }
            level++;
        }
        
        return result;
    }
    
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        buildGraph(root, null, graph);
        return bfs(target.val, k, graph);
    }
}
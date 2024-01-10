/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public void convert(TreeNode current, int parent, Map<Integer, List<Integer>> adj) {
        if (current == null) {
            return;
        }
        if (parent != -1) {
            adj.computeIfAbsent(current.val, k -> new ArrayList<>()).add(parent);
        }
        if (current.left != null) {
            adj.computeIfAbsent(current.val, k -> new ArrayList<>()).add(current.left.val);
        }
        if (current.right != null) {
            adj.computeIfAbsent(current.val, k -> new ArrayList<>()).add(current.right.val);
        }
        convert(current.left, current.val, adj);
        convert(current.right, current.val, adj);
    }
    public int amountOfTime(TreeNode root, int start) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        convert(root, -1, adj);
        
        Queue<Integer> que = new LinkedList<>();
        que.add(start);
        Set<Integer> visited = new HashSet<>();
        visited.add(start);
        int minutes = 0;
        
        while (!que.isEmpty()) {
            int n = que.size();
            
            while (n-- > 0) {
                int curr = que.poll();
                
                for (int ngbr : adj.getOrDefault(curr, Collections.emptyList())) {
                    if (!visited.contains(ngbr)) {
                        que.add(ngbr);
                        visited.add(ngbr);
                    }
                }
            }
            minutes++;
        }
        
        return minutes - 1;
    }
}
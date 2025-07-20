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
    public long kthLargestLevelSum(TreeNode root, int k) {
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        PriorityQueue<Long> pq = new PriorityQueue<>((a, b) -> Long.compare(b, a));

        while (!q.isEmpty()) {
            long sum = 0;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode top = q.poll();
                sum += top.val;
                if (top.left != null) q.offer(top.left);
                if (top.right != null) q.offer(top.right);
            }
            pq.offer(sum);
        }
        
        if (pq.size() < k) return -1;
        while (--k > 0) pq.poll();
        return pq.peek();
    }
}
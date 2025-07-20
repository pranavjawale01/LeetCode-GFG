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
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        Queue<Object[]> queue = new LinkedList<>();
        queue.offer(new Object[]{root, 0L});
        int maxWidth = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            long start = (long) queue.peek()[1];
            Object[] lastElement = (Object[]) queue.toArray(new Object[0])[queue.size() - 1];
            long end = (long) lastElement[1];
            maxWidth = Math.max(maxWidth, (int) (end - start + 1));
            for (int i = 0; i < size; i++) {
                Object[] current = queue.poll();
                TreeNode node = (TreeNode) current[0];
                long index = (long) current[1] - start;

                if (node.left != null) queue.offer(new Object[]{node.left, 2 * index + 1});
                if (node.right != null) queue.offer(new Object[]{node.right, 2 * index + 2});
            }
        }
        return maxWidth;
    }
}
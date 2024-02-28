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
    public int value;
    public int maxDepth;
    public void solve(TreeNode root, int depth) {
        if (root == null) {
            return;
        }
        if (depth > maxDepth) {
            maxDepth = depth;
            value = root.val;
        }
        solve(root.left, depth + 1);
        solve(root.right, depth + 1);
    }
    public int findBottomLeftValue(TreeNode root) {
        maxDepth = -1;
        solve(root, 0);
        return value;
    }
}
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
    public int solve(TreeNode root, int[] moves) {
        if (root == null) {
            return 0;
        }
        int l = solve(root.left, moves);
        int r = solve(root.right, moves);
        int total = l + r + root.val - 1;
        moves[0] += Math.abs(l) + Math.abs(r);
        return total;
    }
    public int distributeCoins(TreeNode root) {
        int[] moves = new int[1];
        if (root.left == null && root.right == null) {
            return 0;
        }
        solve(root, moves);
        return moves[0];
    }
}
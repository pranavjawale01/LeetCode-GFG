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
    public int solve(TreeNode root, int ans) {
        if (root == null) {
            return 0;
        }
        ans = ans * 10 + root.val;
        if (root.left == null && root.right == null) {
            return ans;
        }
        return solve(root.left, ans) + solve(root.right, ans);
    }
    public int sumNumbers(TreeNode root) {
        return solve(root, 0);
    }
}
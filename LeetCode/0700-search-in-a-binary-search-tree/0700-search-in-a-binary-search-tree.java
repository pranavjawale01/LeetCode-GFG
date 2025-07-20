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
    public TreeNode searchBST(TreeNode root, int val) {
        final TreeNode[] ans = new TreeNode[1];
        solve(root, val, ans);
        return ans[0];
    }

    private void solve(TreeNode root, int val, TreeNode[] ans) {
        if (root == null) return;
        if (root.val == val) {
            ans[0] = root;
            return;
        }
        solve(root.left, val, ans);
        solve(root.right, val, ans);
    }
}
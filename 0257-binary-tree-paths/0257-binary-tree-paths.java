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
    private List<String> ans = new ArrayList<>();

    private void solve(TreeNode root, String path) {
        if (root == null) {
            return;
        }
        if (root.left == null && root.right == null) {
            path += root.val;
            ans.add(path);
            return;
        }
        path += root.val + "->";
        solve(root.left, path);
        solve(root.right, path);
    }

    public List<String> binaryTreePaths(TreeNode root) {
        solve(root, "");
        return ans;
    }
}
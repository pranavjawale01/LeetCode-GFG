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
    private int result = 0;

    public int pseudoPalindromicPaths(TreeNode root) {
        solve(root, 0);
        return result;
    }

    private void solve(TreeNode root, int count) {
        if (root == null) {
            return;
        }
        
        count = count ^ (1 << root.val);
        
        if (root.left == null && root.right == null) {
            if ((count & (count - 1)) == 0) {
                result++;
            }
        }

        solve(root.left, count);
        solve(root.right, count);
    }
}
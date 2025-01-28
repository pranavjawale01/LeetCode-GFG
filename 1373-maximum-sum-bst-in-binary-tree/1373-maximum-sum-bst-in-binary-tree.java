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
    int res = 0;

    public int[] solve(TreeNode root) {
        if (root == null) {
            return new int[]{Integer.MAX_VALUE, Integer.MIN_VALUE, 0};
        }
        
        int[] left = solve(root.left);
        int[] right = solve(root.right);
        
        if (left[1] >= root.val || right[0] <= root.val) {
            return new int[]{Integer.MIN_VALUE, Integer.MAX_VALUE, 0};
        }
        
        int sum = left[2] + right[2] + root.val;
        res = Math.max(res, sum);
        
        return new int[]{Math.min(root.val, left[0]), Math.max(root.val, right[1]), sum};
    }

    public int maxSumBST(TreeNode root) {
        solve(root);
        if (res < 0) return 0;
        return res;
    }
}
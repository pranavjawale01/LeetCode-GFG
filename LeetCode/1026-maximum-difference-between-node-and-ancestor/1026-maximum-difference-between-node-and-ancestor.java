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
    int findMaxDiff (TreeNode root, int maxV, int minV) {
        if (root == null) {
            return Math.abs(maxV - minV);
        }
        maxV = Math.max(maxV, root.val);
        minV = Math.min(minV, root.val);
        int l = findMaxDiff(root.left, maxV, minV);
        int r = findMaxDiff(root.right, maxV, minV);
        return Math.max(l, r);
    }
    public int maxAncestorDiff(TreeNode root) {
        return findMaxDiff(root, root.val, root.val);
    }
}
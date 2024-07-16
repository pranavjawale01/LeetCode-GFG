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
    public TreeNode leastCommonAncestor(TreeNode root, int src, int dest) {
        if (root == null) {
            return null;
        }
        if (root.val == src || root.val == dest) {
            return root;
        }
        TreeNode l = leastCommonAncestor(root.left, src, dest);
        TreeNode r = leastCommonAncestor(root.right,src, dest);
        if (l != null && r != null) {
            return root;
        }
        return l != null ? l : r;
    }

    public boolean findPath(TreeNode root, int target, StringBuilder path) {
        if (root == null) {
            return false;
        }
        if (root.val == target) {
            return true;
        }
        path.append("L");
        if (findPath(root.left, target, path)) {
            return true;
        }
        path.deleteCharAt(path.length()-1);
        path.append("R");
        if (findPath(root.right, target, path)) {
            return true;
        }
        path.deleteCharAt(path.length()-1);
        return false;
    }

    public String getDirections(TreeNode root, int startValue, int destValue) {
        TreeNode LCA = leastCommonAncestor(root, startValue, destValue);
        StringBuilder lcaToSrc = new StringBuilder();
        StringBuilder lcaToDes = new StringBuilder();
        findPath(LCA, startValue, lcaToSrc);
        findPath(LCA, destValue,  lcaToDes);
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < lcaToSrc.length(); i++) {
            result.append("U");
        }
        result.append(lcaToDes);
        return result.toString();
    }
}
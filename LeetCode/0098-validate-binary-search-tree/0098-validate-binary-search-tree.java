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
    public boolean isValidBST(TreeNode root) {
        return isValidHelper(root, null, null);
    }
    
    private boolean isValidHelper(TreeNode root, TreeNode minVal, TreeNode maxVal) {
        if (root == null) {
            return true;
        }
        
        if ((minVal != null && root.val <= minVal.val) || (maxVal != null && root.val >= maxVal.val)) {
            return false;
        }
        
        return isValidHelper(root.left, minVal, root) && isValidHelper(root.right, root, maxVal);
    }
}
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
public class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        inorderTraversalRecursive(root, result);
        return result;
    }

    private void inorderTraversalRecursive(TreeNode node, List<Integer> result) {
        if (node == null) {
            return;
        }
        inorderTraversalRecursive(node.left, result);
        result.add(node.val);
        inorderTraversalRecursive(node.right, result);
    }
}
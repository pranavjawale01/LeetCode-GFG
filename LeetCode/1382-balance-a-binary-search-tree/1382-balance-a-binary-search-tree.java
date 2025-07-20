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
    private List<Integer> arr = new ArrayList<>();
    private void inorder(TreeNode root) {
        if (root == null) {
            return;
        }
        inorder(root.left);
        arr.add(root.val);
        inorder(root.right);
    }
    private TreeNode solve(int low, int high) {
        if (low > high) {
            return null;
        }
        int mid = low + (high - low) / 2;
        TreeNode root = new TreeNode(arr.get(mid));
        root.left = solve(low, mid - 1);
        root.right = solve(mid + 1, high);
        return root;
    }
    public TreeNode balanceBST(TreeNode root) {
        inorder(root);
        return solve(0, arr.size()-1);
    }
}
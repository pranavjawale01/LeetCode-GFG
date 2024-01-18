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
    private TreeNode recursive(int[] nums, int low, int high) {
        if (low <= high) {
            int mid = low + (high - low) / 2;
            TreeNode root = new TreeNode(nums[mid]);
            root.left = recursive(nums, low, mid-1);
            root.right = recursive(nums, mid+1, high);
            return root;
        }
        return null;
    }
    public TreeNode sortedArrayToBST(int[] nums) {
        return recursive(nums, 0, nums.length-1);
    }
}
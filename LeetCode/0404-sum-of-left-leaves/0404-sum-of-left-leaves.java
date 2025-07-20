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
    public int solve(TreeNode root, boolean isLeft) {
        if (root == null) {
            return 0;
        }
        if (root.left == null && root.right == null) {
            if (isLeft) {
                return root.val;
            }
        }
        return solve(root.left, true) + solve(root.right, false);
    }
    public int sumOfLeftLeaves(TreeNode root) {
        return solve(root, false);
    }
}

// class Solution {
//     public int solve(TreeNode root, TreeNode parent) {
//         if (root == null) {
//             return 0;
//         }
//         if (root.left == null && root.right == null) {
//             if (parent != null && parent.left == root) {
//                 return root.val;
//             }
//         }
//         return solve(root.left, root) + solve(root.right, root);
//     }
//     public int sumOfLeftLeaves(TreeNode root) {
//         return solve(root, null);
//     }
// }
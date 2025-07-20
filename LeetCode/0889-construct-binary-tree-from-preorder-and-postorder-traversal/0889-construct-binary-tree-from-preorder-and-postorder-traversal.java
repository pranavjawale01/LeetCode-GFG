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
    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        return solve(preorder, postorder, 0, 0, preorder.length);
    }

    private TreeNode solve(int[] preorder, int[] postorder, int preStart, int postStart, int size) {
        if (size == 0) return null;

        TreeNode root = new TreeNode(preorder[preStart]);
        if (size == 1) return root;

        int leftRootVal = preorder[preStart + 1];
        int leftSize = 0;

        for (int i = postStart; i < postStart + size; i++) {
            if (postorder[i] == leftRootVal) {
                leftSize = i - postStart + 1;
                break;
            }
        }

        root.left = solve(preorder, postorder, preStart + 1, postStart, leftSize);
        root.right = solve(preorder, postorder, preStart + 1 + leftSize, postStart + leftSize, size - 1 - leftSize);

        return root;
    }
}
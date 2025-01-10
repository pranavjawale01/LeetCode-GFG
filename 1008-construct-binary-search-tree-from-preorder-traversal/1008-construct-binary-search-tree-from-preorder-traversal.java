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
    public TreeNode bstFromPreorder(int[] preorder) {
        return buildTree(preorder, 0, preorder.length - 1);
    }

    private TreeNode buildTree(int[] preorder, int start, int end) {
        if (start > end) return null;

        TreeNode root = new TreeNode(preorder[start]);
        int idx = start + 1;

        while (idx <= end && preorder[idx] < preorder[start]) {
            idx++;
        }

        root.left = buildTree(preorder, start + 1, idx - 1);
        root.right = buildTree(preorder, idx, end);

        return root;
    }
}
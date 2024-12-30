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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int n = inorder.length;
        return build(inorder, postorder, 0, n - 1, new int[]{n - 1});
    }

    private TreeNode build(int[] inorder, int[] postorder, int inStart, int inEnd, int[] postIndex) {
        if (inStart > inEnd) return null;

        int val = postorder[postIndex[0]--];
        TreeNode root = new TreeNode(val);

        int inIndex = inStart;
        while (inorder[inIndex] != val) inIndex++;

        root.right = build(inorder, postorder, inIndex + 1, inEnd, postIndex);
        root.left = build(inorder, postorder, inStart, inIndex - 1, postIndex);

        return root;
    }
}
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
    public TreeNode constructTree(int[] preorder, int[] inorder, int start, int end, int[] i) {
        if (start > end) {
            return null;
        }
        int rootVal = preorder[i[0]];
        int j = start;
        for (; j <= end; j++) {
            if (inorder[j] == rootVal) {
                break;
            }
        }
        i[0]++;
        TreeNode root = new TreeNode(rootVal);
        root.left = constructTree(preorder, inorder, start, j - 1, i);
        root.right = constructTree(preorder, inorder, j + 1, end, i);

        return root;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int n = preorder.length;
        int[] i = {0};
        return constructTree(preorder, inorder, 0, n - 1, i);
    }
}
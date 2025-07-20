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
    List<Integer> temp = new ArrayList<>();
    private void inorder(TreeNode root) {
        if (root == null) {
            return;
        }
        inorder(root.left);
        temp.add(root.val);
        inorder(root.right);
    }
    private int bs(int val, int[] ans) {
        int low = 0, high = ans.length - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (temp.get(mid) == val) {
                return ans[mid];
            } else if (temp.get(mid) > val) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return val;
    }
    private void solve(TreeNode root, int[] ans) {
        if (root == null) {
            return;
        }
        root.val = bs(root.val, ans);
        solve(root.left, ans);
        solve(root.right,ans);
    }
    public TreeNode bstToGst(TreeNode root) {
        inorder(root);
        int n = temp.size();
        int[] ans = new int[n];
        ans[n-1] = temp.get(n-1);
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = temp.get(i) + ans[i+1];
        }
        solve(root, ans);
        return root;
    }
}
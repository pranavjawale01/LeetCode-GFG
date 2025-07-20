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
    private List<List<Integer>> ans = new ArrayList<>();

    private void solve(TreeNode root, int targetSum, List<Integer> path) {
        if (root == null) {
            return;
        }

        path.add(root.val);
        targetSum -= root.val;

        if (root.left == null && root.right == null) {
            if (targetSum == 0) {
                ans.add(new ArrayList<>(path));
            }
        } else {
            solve(root.left, targetSum, path);
            solve(root.right, targetSum, path);
        }

        path.remove(path.size() - 1);
    }

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        solve(root, targetSum, new ArrayList<>());
        return ans;
    }
}
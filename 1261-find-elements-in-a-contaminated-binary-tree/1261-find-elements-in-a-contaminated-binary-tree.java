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
class FindElements {

    private Set<Integer> set;

    private void dfs(TreeNode root, int x) {
        if (root == null) return;
        root.val = x;
        set.add(x);
        dfs(root.left, 2 * x + 1);
        dfs(root.right, 2 * x + 2);
    }

    public FindElements(TreeNode root) {
        set = new HashSet<>();
        if (root != null) {
            dfs(root, 0);
        }
    }
    
    public boolean find(int target) {
        return set.contains(target);
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */
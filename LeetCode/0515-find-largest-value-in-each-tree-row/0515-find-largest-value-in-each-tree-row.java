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
    public List<Integer> largestValues(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        List<Integer> ans = new ArrayList<>();
        if (root == null) return ans;
        ans.add(root.val);
        while (!q.isEmpty()) {
            int n = q.size();
            boolean flag = false;
            int maxVal = 0;
            while (n-- > 0) {
                TreeNode temp = q.poll();
                if (temp.left != null) {
                    if (flag == false) maxVal = temp.left.val;
                    flag = true;
                    q.offer(temp.left);
                    maxVal = Math.max(maxVal, temp.left.val);
                }
                if (temp.right != null) {
                    if (flag == false) maxVal = temp.right.val;
                    flag = true;
                    q.offer(temp.right);
                    maxVal = Math.max(maxVal, temp.right.val);
                }
            }
            if (flag) ans.add(maxVal);
        }
        return ans;
    }
}
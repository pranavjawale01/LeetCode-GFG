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
    public TreeNode createBinaryTree(int[][] descriptions) {
        Map<Integer, TreeNode> mp = new HashMap<>();
        Set<Integer> childSet = new HashSet<>();
        for (int[] x : descriptions) {
            int p = x[0];
            int c = x[1];
            int l = x[2];
            mp.putIfAbsent(p, new TreeNode(p));
            mp.putIfAbsent(c, new TreeNode(c));
            if (l == 1) {
                mp.get(p).left = mp.get(c);
            } else {
                mp.get(p).right = mp.get(c);
            }
            childSet.add(c);
        }
        for (int[] x : descriptions) {
            int p = x[0];
            if (!childSet.contains(p)) {
                return mp.get(p);
            }
        }
        return null;
    }
}
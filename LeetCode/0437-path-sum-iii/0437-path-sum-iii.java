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
    public int solve(TreeNode root, long curr, int target, Map<Long, Integer> mp) {
        if (root == null) {
            return 0;
        }
        curr += root.val;
        int count = 0;
        if (mp.containsKey(curr - target)) {
            count = mp.get(curr - target);
        }
        mp.put(curr, mp.getOrDefault(curr, 0) + 1);
        count += solve(root.left, curr, target, mp);
        count += solve(root.right,curr, target, mp);
        mp.put(curr, mp.getOrDefault(curr, 0) - 1);
        return count;
    }
    public int pathSum(TreeNode root, int targetSum) {
        Map<Long, Integer> mp = new HashMap<>();   
        mp.put(0L, 1);
        return solve(root, 0L, targetSum, mp);     
    }
}
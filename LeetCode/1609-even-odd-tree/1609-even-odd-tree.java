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
    private List<Integer> levelPrev = new ArrayList<>();
    private boolean solve(TreeNode root, int level) {
        if (root == null) {
            return true;
        }

        if ((level % 2 == 0 && root.val % 2 == 0) || (level % 2 != 0 && root.val % 2 != 0)) {
            return false;
        }

        if (level >= levelPrev.size()) {
            levelPrev.add(root.val);
        } else {
            if ((level % 2 == 0 && root.val <= levelPrev.get(level)) || (level % 2 != 0 && root.val >= levelPrev.get(level))) {
                return false;
            }
            levelPrev.set(level, root.val);
        }
        return solve(root.left, level + 1) && solve(root.right, level + 1);
    }
    public boolean isEvenOddTree(TreeNode root) {
        return solve(root, 0);
    }
}

// class Solution {
//     public boolean isEvenOddTree(TreeNode root) {
//         Queue<TreeNode> q = new LinkedList<>();
//         q.offer(root);
//         boolean evenLevel = true;
//         while (!q.isEmpty()) {
//             int n = q.size();
//             int prev = evenLevel ? Integer.MIN_VALUE : Integer.MAX_VALUE;
//             while (n-- > 0) {
//                 TreeNode temp = q.poll();
//                 if (temp.left != null) {
//                     q.offer(temp.left);
//                 }
//                 if (temp.right != null) {
//                     q.offer(temp.right);
//                 }
//                 if (evenLevel && (temp.val % 2 == 0 || temp.val <= prev)) {
//                     return false;
//                 }
//                 if (!evenLevel && (temp.val % 2 != 0 || temp.val >= prev)) {
//                     return false;
//                 }
//                 prev = temp.val;
//             }
//             evenLevel = !evenLevel;
//         }
//         return true;
//     }
// }
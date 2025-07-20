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
    public int findBottomLeftValue(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        int value = 0;
        while (!q.isEmpty()) {
            int n = q.size();
            while (n > 0) {
                TreeNode temp = q.poll();
                value = temp.val;
                if (temp.right != null) {
                    q.offer(temp.right);
                }
                if (temp.left != null) {
                    q.offer(temp.left);
                }
                n -= 1;
            }
        }
        return value;
    }
}

// class Solution {
//     public int findBottomLeftValue(TreeNode root) {
//         Queue<TreeNode> q = new LinkedList<>();
//         q.offer(root);
//         int value = 0;
//         while (!q.isEmpty()) {
//             TreeNode temp = q.poll();
//             value = temp.val;
//             if (temp.right != null) {
//                 q.offer(temp.right);
//             }
//             if (temp.left != null) {
//                 q.offer(temp.left);
//             }
//         }
//         return value;
//     }
// }

// /**
//  * Definition for a binary tree node.
//  * public class TreeNode {
//  *     int val;
//  *     TreeNode left;
//  *     TreeNode right;
//  *     TreeNode() {}
//  *     TreeNode(int val) { this.val = val; }
//  *     TreeNode(int val, TreeNode left, TreeNode right) {
//  *         this.val = val;
//  *         this.left = left;
//  *         this.right = right;
//  *     }
//  * }
//  */
// class Solution {
//     public int value;
//     public int maxDepth;
//     public void solve(TreeNode root, int depth) {
//         if (root == null) {
//             return;
//         }
//         if (depth > maxDepth) {
//             maxDepth = depth;
//             value = root.val;
//         }
//         solve(root.left, depth + 1);
//         solve(root.right, depth + 1);
//     }
//     public int findBottomLeftValue(TreeNode root) {
//         maxDepth = -1;
//         solve(root, 0);
//         return value;
//     }
// }
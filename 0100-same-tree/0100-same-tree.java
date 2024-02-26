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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) {
            return true;
        }
        if (p == null || q == null) {
            return false;
        }
        Queue<TreeNode> a = new LinkedList<>();
        Queue<TreeNode> b = new LinkedList<>();
        a.add(p);
        b.add(q);
        while (!a.isEmpty() && !b.isEmpty()) {
            TreeNode temp1 = a.poll();
            TreeNode temp2 = b.poll();
            if (temp1.val != temp2.val) {
                return false;
            }
            if (temp1.left != null && temp2.left != null) {
                a.add(temp1.left);
                b.add(temp2.left);
            } else if (temp1.left != null || temp2.left != null) {
                return false;
            }
            if (temp1.right != null && temp2.right != null) {
                a.add(temp1.right);
                b.add(temp2.right);
            } else if (temp1.right != null || temp2.right != null) {
                return false;
            }
        }
        return true;
    }
}

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
//     public boolean isSameTree(TreeNode p, TreeNode q) {
//         if (p == null && q == null) {
//             return true;
//         }
//         if (p == null || q == null) {
//             return false;
//         }
//         return (p.val == q.val) && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
//     }
// }
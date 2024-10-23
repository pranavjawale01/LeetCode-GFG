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
    public TreeNode replaceValueInTree(TreeNode root) {
        if (root == null) return root;

        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        int levelSum = root.val;

        while (!q.isEmpty()) {
            int n = q.size();
            int nextLevelSum = 0;

            for (int i = 0; i < n; i++) {
                TreeNode curr = q.poll();
                curr.val = levelSum - curr.val;
                int siblingSum = (curr.left != null ? curr.left.val : 0) + (curr.right != null ? curr.right.val : 0);

                if (curr.left != null) {
                    nextLevelSum += curr.left.val;
                    curr.left.val = siblingSum;
                    q.offer(curr.left);
                }
                if (curr.right != null) {
                    nextLevelSum += curr.right.val;
                    curr.right.val = siblingSum;
                    q.offer(curr.right);
                }
            }
            levelSum = nextLevelSum;
        }

        return root;
    }
}





// class Solution {
//     public TreeNode replaceValueInTree(TreeNode root) {
//         if (root == null) return root;

//         Queue<TreeNode> q = new LinkedList<>();
//         q.offer(root);
//         List<Integer> levelSum = new ArrayList<>();

//         while (!q.isEmpty()) {
//             int currLvlSum = 0;
//             int n = q.size();
//             for (int i = 0; i < n; i++) {
//                 TreeNode curr = q.poll();
//                 currLvlSum += curr.val;
//                 if (curr.left != null) {
//                     q.offer(curr.left);
//                 }
//                 if (curr.right != null) {
//                     q.offer(curr.right);
//                 }
//             }
//             levelSum.add(currLvlSum);
//         }

//         q.offer(root);
//         root.val = 0;
//         int level = 1;

//         while (!q.isEmpty()) {
//             int n = q.size();
//             for (int i = 0; i < n; i++) {
//                 TreeNode curr = q.poll();
//                 int siblingSum = (curr.left != null ? curr.left.val : 0) + (curr.right != null ? curr.right.val : 0);

//                 if (curr.left != null) {
//                     curr.left.val = levelSum.get(level) - siblingSum;
//                     q.offer(curr.left);
//                 }
//                 if (curr.right != null) {
//                     curr.right.val = levelSum.get(level) - siblingSum;
//                     q.offer(curr.right);
//                 }
//             }
//             level++;
//         }

//         return root;
//     }
// }
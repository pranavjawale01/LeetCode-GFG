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
    public TreeNode reverseOddLevels(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int level = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            List<TreeNode> levelNodes = new ArrayList<>();

            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                levelNodes.add(node);

                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }

            if (level % 2 == 1) {
                int left = 0, right = levelNodes.size() - 1;
                while (left < right) {
                    int temp = levelNodes.get(left).val;
                    levelNodes.get(left).val = levelNodes.get(right).val;
                    levelNodes.get(right).val = temp;
                    left++;
                    right--;
                }
            }
            level++;
        }
        return root;
    }
}





// class Solution {
//     public void solve(TreeNode l, TreeNode r, int lvl) {
//         if (l == null || r == null) {
//             return;
//         }
//         if (lvl % 2 == 1) {
//             int temp = l.val;
//             l.val = r.val;
//             r.val = temp;
//         }
//         solve(l.left, r.right, lvl + 1);
//         solve(l.right, r.left, lvl + 1);
//     }

//     public TreeNode reverseOddLevels(TreeNode root) {
//         solve(root.left, root.right, 1);
//         return root;
//     }
// }
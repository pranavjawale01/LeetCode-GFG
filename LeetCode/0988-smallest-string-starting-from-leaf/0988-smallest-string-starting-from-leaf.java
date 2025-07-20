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
    public String smallestFromLeaf(TreeNode root) {
        Queue<Pair<TreeNode, String>> q = new LinkedList<>();
        q.add(new Pair<>(root, String.valueOf((char)(root.val + 'a'))));
        String result = "";
        while (!q.isEmpty()) {
            Pair<TreeNode, String> pair = q.poll();
            TreeNode node = pair.getKey();
            String curr = pair.getValue();
            if (node.left == null && node.right == null) {
                if (result.isEmpty() || result.compareTo(curr) > 0) {
                    result = curr;
                }
            }
            if (node.left != null) {
                q.add(new Pair<>(node.left, (char)(node.left.val + 'a') + curr));
            }
            if (node.right != null) {
                q.add(new Pair<>(node.right, (char)(node.right.val + 'a') + curr));
            }
        }
        return result;
    }
}

// class Solution {
//     public void solve(TreeNode root, StringBuilder sb, StringBuilder result) {
//         if (root == null) {
//             return;
//         }
//         sb.insert(0, (char)(root.val + 'a'));
//         if (root.left == null && root.right == null) {
//             if (result.length() == 0 || sb.toString().compareTo(result.toString()) < 0) {
//                 result.setLength(0);
//                 result.append(sb);
//             }
//             sb.deleteCharAt(0);
//             return;
//         }
//         solve(root.left, sb, result);
//         solve(root.right, sb, result);
//         sb.deleteCharAt(0);
//     }
    
//     public String smallestFromLeaf(TreeNode root) {
//         StringBuilder result = new StringBuilder();
//         solve(root, new StringBuilder(), result);
//         return result.toString();
//     }
// }
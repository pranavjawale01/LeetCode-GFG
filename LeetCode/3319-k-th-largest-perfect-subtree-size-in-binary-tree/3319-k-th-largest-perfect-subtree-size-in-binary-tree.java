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
    private List<Integer> arr = new ArrayList<>();

    private Pair<Boolean, Pair<Integer, Integer>> solveTree(TreeNode root) {
        if (root == null) {
            return new Pair<>(true, new Pair<>(0, 0));
        }
        Pair<Boolean, Pair<Integer, Integer>> left = solveTree(root.left);
        Pair<Boolean, Pair<Integer, Integer>> right = solveTree(root.right);
        boolean leftBal = left.getKey();
        boolean rightBal = right.getKey();
        int leftHt = left.getValue().getKey(), leftSz = left.getValue().getValue();
        int rightHt = right.getValue().getKey(), rightSz = right.getValue().getValue();
        if (leftBal && rightBal && leftHt == rightHt) {
            int len = leftSz + rightSz + 1;
            int ht = leftHt + 1;
            arr.add(len);
            return new Pair<>(true, new Pair<>(ht, len));
        }
        return new Pair<>(false, new Pair<>(0, 0));
    }

    public int kthLargestPerfectSubtree(TreeNode root, int k) {
        solveTree(root);
        Collections.sort(arr);
        Collections.reverse(arr);
        if (arr.size() >= k) {
            return arr.get(k - 1);
        }
        return -1;
    }
}
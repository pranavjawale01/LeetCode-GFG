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
    private int countMinSwap(List<Integer> arr) {
        int swaps = 0;
        List<Integer> sorted = new ArrayList<>(arr);
        Collections.sort(sorted);
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < arr.size(); i++) {
            mp.put(arr.get(i), i);
        }
        for (int i = 0; i < arr.size(); i++) {
            if (arr.get(i).equals(sorted.get(i))) {
                continue;
            }
            int currIdx = mp.get(sorted.get(i));
            mp.put(arr.get(i), currIdx);
            mp.put(arr.get(currIdx), i);
            Collections.swap(arr, i, currIdx);
            swaps++;
        }
        return swaps;
    }

    public int minimumOperations(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        int ans = 0;
        while (!q.isEmpty()) {
            int n = q.size();
            List<Integer> arr = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                TreeNode temp = q.poll();
                arr.add(temp.val);
                if (temp.left != null) {
                    q.offer(temp.left);
                }
                if (temp.right != null) {
                    q.offer(temp.right);
                }
            }
            ans += countMinSwap(arr);
        }
        return ans;
    }
}
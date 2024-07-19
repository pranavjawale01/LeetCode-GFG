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
    public List<Integer> solve(TreeNode root, int distance, int[] goodLeaf) {
        if (root == null) {
            return new ArrayList<>();
        }
        if (root.left == null && root.right == null) {
            return new ArrayList<>(List.of(1));
        }
        List<Integer> left = solve(root.left, distance, goodLeaf);
        List<Integer> right = solve(root.right, distance, goodLeaf);
        for (int l : left) {
            for (int r : right) {
                if (l != 0 && r != 0 && l + r <= distance) {
                    goodLeaf[0]++;
                }
            }
        }
        List<Integer> curr = new ArrayList<>();
        for (int l : left) {
            if (l != 0 && l + 1 <= distance) {
                curr.add(l + 1);
            }
        }
        for (int r : right) {
            if (r != 0 && r + 1 <= distance) {
                curr.add(r + 1);
            }
        }
        return curr;
    }

    public int countPairs(TreeNode root, int distance) {
        int[] goodLeaf = new int[1];
        solve(root, distance, goodLeaf);
        return goodLeaf[0];
    }
}





// class Solution {
//     public void makeGraph(TreeNode root, TreeNode prev, Map<TreeNode, List<TreeNode>> mp, Set<TreeNode> st) {
//         if (root == null) {
//             return;
//         }
//         if (root.left == null && root.right == null) {
//             st.add(root);
//         }
//         if (prev != null) {
//             mp.computeIfAbsent(root, k -> new ArrayList<>()).add(prev);
//             mp.computeIfAbsent(prev, k -> new ArrayList<>()).add(root);
//         }
//         makeGraph(root.left, root, mp, st);
//         makeGraph(root.right,root, mp, st);
//     }
    
//     public int countPairs(TreeNode root, int distance) {
//         Map<TreeNode, List<TreeNode>> mp = new HashMap<>();
//         Set<TreeNode> st = new HashSet<>();
//         makeGraph(root, null, mp, st);
//         int count = 0;
//         for (TreeNode leaf : st) {
//             Queue<TreeNode> q = new LinkedList<>();
//             Set<TreeNode> vis = new HashSet<>();
//             q.add(leaf);
//             vis.add(leaf);
//             for (int level = 0; level <= distance; level++) {
//                 int size = q.size();
//                 while (size-- > 0) {
//                     TreeNode curr = q.poll();
//                     if (curr != leaf && st.contains(curr)) {
//                         count++;
//                     }
//                     for (TreeNode x : mp.getOrDefault(curr, new ArrayList<>())) {
//                         if (!vis.contains(x)) {
//                             q.add(x);
//                             vis.add(x);
//                         }
//                     }
//                 }
//             }
//         }
//         return count / 2;
//     }
// }
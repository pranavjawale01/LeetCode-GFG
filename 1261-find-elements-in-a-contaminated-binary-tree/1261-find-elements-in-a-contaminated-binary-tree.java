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
class FindElements {
    private Set<Integer> set;

    private void bfs(TreeNode root, int x) {
        Queue<TreeNode> queue = new LinkedList<>();
        root.val = x;
        queue.add(root);

        while (!queue.isEmpty()) {
            TreeNode temp = queue.poll();
            set.add(temp.val);

            if (temp.left != null) {
                temp.left.val = 2 * temp.val + 1;
                queue.add(temp.left);
            }
            if (temp.right != null) {
                temp.right.val = 2 * temp.val + 2;
                queue.add(temp.right);
            }
        }
    }

    public FindElements(TreeNode root) {
        set = new HashSet<>();
        if (root != null) {
            bfs(root, 0);
        }
    }
    
    public boolean find(int target) {
        return set.contains(target);
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */








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
// class FindElements {

//     private Set<Integer> set;

//     private void dfs(TreeNode root, int x) {
//         if (root == null) return;
//         root.val = x;
//         set.add(x);
//         dfs(root.left, 2 * x + 1);
//         dfs(root.right, 2 * x + 2);
//     }

//     public FindElements(TreeNode root) {
//         set = new HashSet<>();
//         if (root != null) {
//             dfs(root, 0);
//         }
//     }
    
//     public boolean find(int target) {
//         return set.contains(target);
//     }
// }

// /**
//  * Your FindElements object will be instantiated and called as such:
//  * FindElements obj = new FindElements(root);
//  * boolean param_1 = obj.find(target);
//  */
/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ArrayList<Integer> inorderTraversal(TreeNode root) {
        Stack <TreeNode> stack = new Stack <TreeNode>();
        ArrayList<Integer> list = new ArrayList<Integer>();
        if(root==null)
        {
            return list;
        }
        TreeNode node =root;
        while(!stack.isEmpty() || node!=null )
        {
            if(node !=null)
            {
                stack.push(node);
                node=node.left;
            }
            else
            {
                TreeNode p = stack.pop();
                list.add(p.val);
                node=p.right;
            }
        }
        return list;
    }
}
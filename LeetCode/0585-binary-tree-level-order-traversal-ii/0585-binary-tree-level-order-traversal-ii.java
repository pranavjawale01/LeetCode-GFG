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
    public ArrayList<ArrayList<Integer>> levelOrderBottom(TreeNode root) {
        ArrayList<TreeNode> queue = new ArrayList<TreeNode>();
        ArrayList<ArrayList<Integer>> r = new ArrayList<ArrayList<Integer>>();
        TreeNode p = null;
        int i = 0;
        if(root == null){
            return r;
        }
        
        queue.add(root);
        queue.add(new TreeNode(-255));
        
        while(i < queue.size()){
            
            p = queue.get(i);
            
            if(p.val != -255){
                if(p.right != null){
                    queue.add(p.right);
                }
                
                if(p.left != null){
                    queue.add(p.left);
                }
            }
            else{
                if(i != queue.size() - 1){
                    queue.add(new TreeNode(-255));
                }
            }
            
            i++;
            
        }
        
        ArrayList<Integer> row = new ArrayList<Integer>();
        
        for(int j = queue.size() - 1; j >= 0; j--){
            
            if(queue.get(j).val == -255){
                row.clear();
                if(j != queue.size() -1){
                    r.add(row);
                }
            }
            else{
                row.add(queue.get(j).val);
            }
            
        }
        
        return r;
    }
}
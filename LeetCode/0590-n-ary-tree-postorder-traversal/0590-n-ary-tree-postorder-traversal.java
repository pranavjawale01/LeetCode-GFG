/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<Integer> postorder(Node root) {
        if (root == null) {
            return new ArrayList<>();
        }
        
        List<Integer> ans = new ArrayList<>();
        Stack<Node> st = new Stack<>();
        st.push(root);
        
        while (!st.isEmpty()) {
            Node temp = st.pop();
            ans.add(temp.val);
            
            for (Node child : temp.children) {
                st.push(child);
            }
        }
        
        Collections.reverse(ans);
        return ans;
    }
}







// class Solution {
//     private List<Integer> ans = new ArrayList<>();
//     private void solve(Node root) {
//         if (root == null) {
//             return;
//         }
//         for (Node child : root.children) {
//             solve(child);
//         }
//         ans.add(root.val);
//     }
//     public List<Integer> postorder(Node root) {
//         solve(root);
//         return ans;
//     }
// }
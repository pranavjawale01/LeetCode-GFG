/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    private Map<Node, Node> mp = new HashMap<>();
    
    public void DFS(Node node, Node clone_node) {
        for (Node n : node.neighbors) {
            if (mp.containsKey(n)) {
                clone_node.neighbors.add(mp.get(n));
            } else {
                Node clone = new Node(n.val);
                mp.put(n, clone);
                clone_node.neighbors.add(clone);
                DFS(n, clone);
            }
        }
    }
    
    public Node cloneGraph(Node node) {
        if (node == null) {
            return null;
        }
        Node clone_node = new Node(node.val);
        mp.put(node, clone_node);
        DFS(node, clone_node);
        return clone_node;
    }
}
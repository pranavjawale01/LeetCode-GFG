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
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> map = new TreeMap<>();
        Queue<Pair<TreeNode, Pair<Integer, Integer>>> q = new LinkedList<>();
        q.offer(new Pair<>(root, new Pair<>(0, 0)));
        
        while (!q.isEmpty()) {
            Pair<TreeNode, Pair<Integer, Integer>> p = q.poll();
            TreeNode node = p.getKey();
            int col = p.getValue().getKey();
            int row = p.getValue().getValue();
            
            map.putIfAbsent(col, new TreeMap<>());
            map.get(col).putIfAbsent(row, new PriorityQueue<>());
            map.get(col).get(row).offer(node.val);
            
            if (node.left != null) {
                q.offer(new Pair<>(node.left, new Pair<>(col - 1, row + 1)));
            }
            if (node.right != null) {
                q.offer(new Pair<>(node.right, new Pair<>(col + 1, row + 1)));
            }
        }
        
        List<List<Integer>> result = new ArrayList<>();
        for (TreeMap<Integer, PriorityQueue<Integer>> colMap : map.values()) {
            List<Integer> colList = new ArrayList<>();
            for (PriorityQueue<Integer> nodes : colMap.values()) {
                while (!nodes.isEmpty()) {
                    colList.add(nodes.poll());
                }
            }
            result.add(colList);
        }
        
        return result;
    }
    
    static class Pair<K, V> {
        private K key;
        private V value;
        public Pair(K key, V value) { this.key = key; this.value = value; }
        public K getKey() { return key; }
        public V getValue() { return value; }
    }
}
class Solution {
    int[] res, count;
    ArrayList<HashSet<Integer>> tree;
    public int[] sumOfDistancesInTree(int n, int[][] edges) {
        tree = new ArrayList<HashSet<Integer>>();
        res = new int[n];
        count = new int[n];
        for(int i = 0; i < n; i++)
            tree.add(new HashSet<>());
        
        for(int[] e: edges) {
            tree.get(e[0]).add(e[1]);
            tree.get(e[1]).add(e[0]);
        }
        dfsBase(0, -1);
        dfs(0, -1);
        return res;
    }
    
    public void dfsBase(int root, int pre) {
        for(int i : tree.get(root)) {
            if(i == pre)
                continue;
            dfsBase(i, root);
            count[root] += count[i];
            res[root] += res[i] + count[i];
        }
        count[root]++;
    }
    
    public void dfs(int root, int pre) {
        for(int i: tree.get(root)) {
            if(i == pre)
                continue;
            res[i] = res[root] - count[i] + count.length - count[i];
            dfs(i, root);
        }
    }
}
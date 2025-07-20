class Solution {
    public int[] parent = new int[26];
    public int[] rank = new int[26];

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void union(int x, int y) {
        int parX = find(x);
        int parY = find(y);

        if (parX != parY) {
            if (rank[parX] > rank[parY]) {
                parent[parY] = parX;
            } else if (rank[parX] < rank[parY]) {
                parent[parX] = parY;
            } else {
                parent[parY] = parX;
                rank[parX]++;
            }
        }
    }

    public boolean equationsPossible(String[] equations) {
        for (int i = 0; i < 26; i++) {
            rank[i] = 1;
            parent[i] = i;
        }
        for (String s : equations) {
            if (s.charAt(1) == '=') {
                union(s.charAt(0) - 'a', s.charAt(3) - 'a');
            }
        }
        for (String s : equations) {
            if (s.charAt(1) == '!') {
                if (find(s.charAt(0) - 'a') == find(s.charAt(3) - 'a')) {
                    return false;
                }
            }
        }
        return true;
    }
}
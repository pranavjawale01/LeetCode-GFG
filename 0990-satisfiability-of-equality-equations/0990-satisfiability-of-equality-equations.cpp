class Solution {
public:
    vector<int> parent;
    vector<int> rank; 

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void Union(int x, int y) {
        int parentX = find(x);
        int parentY = find(y);
        if (parentX != parentY) {
            if (rank[parentX] < rank[parentY]) {
                parent[parentX] = parentY;
            } else if (rank[parentX] > rank[parentY]) {
                parent[parentY] = parentX;
            } else {
                parent[parentX] = parentY;
                rank[parentY]++;
            }
        }
    }

    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        rank.resize(26, 0);
        parent.resize(26, 0);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        for (auto s : equations) {
            if (s[1] == '=') {
                Union(s[0] - 'a', s[3] - 'a');
            }
        }
        for (string &s : equations) {
            if (s[1] == '!') {
                if (find(s[0] - 'a') == find(s[3] - 'a')) {
                    return false;
                }
            }
        }
        return true;
    }
};
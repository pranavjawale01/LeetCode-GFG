class Solution {
public:
    class SegmentTree {
    public:
        vector<int> st;
        vector<int> lazy;
        int n;

        SegmentTree(int n) {
            this->n = n;
            st.resize(4 * n, 0);
            lazy.resize(4 * n, -1);
            buildTree(0, 0, n - 1);
        }

        void buildTree(int i, int low, int high) {
            if (low == high) {
                st[i] = low == 0 ? 0 : 1;
                return;
            }
            int mid = low + (high - low) / 2;
            buildTree(2 * i + 1, low, mid);
            buildTree(2 * i + 2, mid + 1, high);
            st[i] = st[2 * i + 1] + st[2 * i + 2];
        }

        int query() {
            return st[0];
        }

        void update(int left, int right) {
            update(0, 0, n - 1, left, right);
        }

        void propagate(int i, int low, int high) {
            if (lazy[i] != -1) {
                st[i] = 0;
                if (low != high) {
                    lazy[2 * i + 1] = lazy[i];
                    lazy[2 * i + 2] = lazy[i];
                }
                lazy[i] = -1;
            }
        }

        void update(int i, int low, int high, int left, int right) {
            propagate(i, low, high);
            if (low > right || high < left) {
                return;
            }
            if (low >= left && high <= right) {
                st[i] = 0;
                if (low != high) {
                    lazy[2 * i + 1] = 0;
                    lazy[2 * i + 2] = 0;
                }
                return;
            }
            int mid = low + (high - low) / 2;
            update(2 * i + 1, low, mid, left, right);
            update(2 * i + 2, mid + 1, high, left, right);
            st[i] = st[2 * i + 1] + st[2 * i + 2];
        }
    };

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        SegmentTree seg(n);
        vector<int> ans;
        for (auto& x : queries) {
            int u = x[0];
            int v = x[1];
            seg.update(u + 1, v - 1);
            ans.push_back(seg.query());
        }
        return ans;
    }
};





// class Solution {
// public:
//     vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
//         set<int> st;
//         for (int i = 0; i < n; i++) {
//             st.insert(i);
//         }
//         vector<int> ans;
//         for (auto x : queries) {
//             auto a = st.lower_bound(x[0] + 1);
//             auto b = st.upper_bound(x[1] - 1);
//             st.erase(a, b);
//             ans.push_back(st.size() - 1);
//         }
//         return ans;
//     }
// };
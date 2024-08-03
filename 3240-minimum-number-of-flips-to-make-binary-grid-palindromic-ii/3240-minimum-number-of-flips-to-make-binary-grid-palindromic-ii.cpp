class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        
        if (n % 2 == 1 && m % 2 == 1) {
            if (grid[n / 2][m / 2] == 1) {
                ans += 1;
            }
        }

        vector<int> shift(3, 0);
        if (n % 2 == 1) {
            int a = 0, b = m - 1;
            while (a < b) {
                int sm = grid[n / 2][a] + grid[n / 2][b];
                shift[sm] += 1;
                a += 1;
                b -= 1;
            }
        }

        if (m % 2 == 1) {
            int a = 0, b = n - 1;
            while (a < b) {
                int sm = grid[a][m / 2] + grid[b][m / 2];
                shift[sm] += 1;
                a += 1;
                b -= 1;
            }
        }

        if (shift[2] % 2 == 1) {
            if (shift[1] > 0) {
                ans += shift[1];
            } else {
                ans += 2;
            }
        } else {
            ans += shift[1];
        }

        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < m / 2; ++j) {
                int a = grid[i][j];
                int b = grid[n - 1 - i][j];
                int c = grid[i][m - 1 - j];
                int d = grid[n - 1 - i][m - 1 - j];

                int sm = a + b + c + d;

                if (sm != 0 && sm != 4) {
                    ans += min(sm, 4 - sm);
                }
            }
        }

        return ans;
    }
};
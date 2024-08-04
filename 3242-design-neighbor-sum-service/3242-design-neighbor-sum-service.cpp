class neighborSum {
public:
    vector<vector<int>> arr;
    int row;
    int col;
    unordered_map<int, pair<int, int>> mp;
    
    neighborSum(vector<vector<int>>& grid) {
        arr = grid;
        row = grid.size();
        col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                mp[grid[i][j]] = {i, j};
            }
        }
    }
    
    int adjacentSum(int value) {
        if (mp.find(value) == mp.end()) {
            return 0;
        }
        int x = mp[value].first;
        int y = mp[value].second;
        int sum = 0;
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (auto d : dirs) {
            int a = d.first + x;
            int b = d.second + y;
            if (a >= 0 && a < row && b >= 0 && b < col) {
                sum += arr[a][b];
            }
        }
        return sum;
    }
    
    int diagonalSum(int value) {
        if (mp.find(value) == mp.end()) {
            return 0;
        }
        int x = mp[value].first;
        int y = mp[value].second;
        int sum = 0;
        vector<pair<int, int>> dirs = {{-1, -1}, {1, -1}, {1, 1}, {-1, 1}};
        for (auto d : dirs) {
            int a = d.first + x;
            int b = d.second + y;
            if (a >= 0 && a < row && b >= 0 && b < col) {
                sum += arr[a][b];
            }
        }
        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row = maze.size(), col = maze[0].size();
        queue<vector<int>> q;
        q.push(entrance);
        maze[entrance[0]][entrance[1]] = '+';

        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int steps = 0;
        int x, y;
        while (!q.empty()) {
            int n = q.size();
            steps++;
            for (int i = 0; i < n; i++) {
                auto curr = q.front();
                q.pop();
                for (auto direction : directions) {
                    x = curr[0] + direction[0];
                    y = curr[1] + direction[1];
                    if (x < 0 || y < 0 || x >= row || y >= col || maze[x][y] == '+') {
                        continue;
                    }
                    if (x == 0 || x == row - 1 || y == 0 || y == col - 1) {
                        return steps;
                    }
                    maze[x][y] = '+';
                    q.push({x, y});
                }
            }
        }
        return -1;
    }
};



// class Solution {
// public:
//     int n , m;
//     vector<vector<vector<int>>> memo;
    
//     int solve(int i , int j , int curr , vector<vector<char>>& maze) {
//         if(i < 0 || i == n || j < 0 || j == m || maze[i][j] == '+')
//             return INT_MAX;
        
//         if((i == 0 || j == 0 || i == n - 1 || j == m - 1) && curr != 0)
//             return curr;
        
//         if(memo[i][j][curr] != -1)
//             return memo[i][j][curr];
        
//         maze[i][j] = '+';
        
//         int up = solve(i - 1 , j , curr + 1 , maze);
//         int down = solve(i + 1 , j , curr + 1 , maze);
//         int left = solve(i , j - 1 , curr + 1 , maze);
//         int right = solve(i , j + 1 , curr + 1 , maze);
        
//         int minSteps = min(min(left , right) , min(up , down));
//         memo[i][j][curr] = minSteps;
//         return minSteps;
//     }
    
//     int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
//         n = maze.size() , m = maze[0].size();
//         memo.assign(n, vector<vector<int>>(m, vector<int>(n * m, -1)));
        
//         int ans = solve(entrance[0] , entrance[1] , 0 , maze);
        
//         return (ans == INT_MAX ? -1 : ans);
//     }
// };   
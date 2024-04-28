class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        vector<bool> visited(n, false);
        visited[0] = true;
        for (int room : rooms[0]) {
            q.push(room);
        }
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            visited[temp] = true;
            for (int room : rooms[temp]) {
                if (!visited[room]) {
                    q.push(room);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
};


// class Solution {
// public:
//     void solve(vector<vector<int>>& rooms, vector<bool> &visited, int i) {
//         if (visited[i] == true) {
//             return;
//         }
//         visited[i] = true;
//         for (int room : rooms[i]) {
//             solve(rooms, visited, room);
//         }
//     }
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         int n = rooms.size();
//         vector<bool> visited(n, false);
//         visited[0] = true;
//         for (int room : rooms[0]) {
//             solve(rooms, visited, room);
//         }

//         for (int i = 0; i < n; i++) {
//             if (!visited[i]) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };
class Solution {
public:
    void solve(vector<vector<int>>& rooms, vector<bool> &visited, int i) {
        if (visited[i] == true) {
            return;
        }
        visited[i] = true;
        for (int room : rooms[i]) {
            solve(rooms, visited, room);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        visited[0] = true;
        for (int room : rooms[0]) {
            solve(rooms, visited, room);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
};
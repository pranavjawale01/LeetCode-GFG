class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(meetings.begin(), meetings.end());

        vector<int> roomUsedCount(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> usedRoom; // Corrected typos
        priority_queue<int, vector<int>, greater<int>> availableRoom;

        for (int room = 0; room < n; room++) {
            availableRoom.push(room);
        }

        for (vector<int>& meet : meetings) {
            int start = meet[0];
            int end = meet[1];

            while (!usedRoom.empty() && usedRoom.top().first <= start) {
                int room = usedRoom.top().second;
                usedRoom.pop();
                availableRoom.push(room);
            }

            if (!availableRoom.empty()) {
                int room = availableRoom.top();
                availableRoom.pop();
                usedRoom.push({end, room});
                roomUsedCount[room]++;
            } else {
                int room = usedRoom.top().second;
                int endTime = usedRoom.top().first;
                usedRoom.pop();
                usedRoom.push({endTime + (end - start), room});
                roomUsedCount[room]++;
            }
        }

        int resultRoom = -1;
        int maxUse = 0;
        for (int room = 0; room < n; room++) {
            if (roomUsedCount[room] > maxUse) {
                maxUse = roomUsedCount[room];
                resultRoom = room;
            }
        }
        return resultRoom;
    }
};

// class Solution {
// public:
//     int mostBooked(int n, vector<vector<int>>& meetings) {
//         sort(meetings.begin(), meetings.end());
//         int m = meetings.size();
//         vector<long long> lastAvailableAt(n, 0);
//         vector<int> roomsUsedCount(n , 0);
//         for (vector<int>& meet : meetings) {
//             int start = meet[0];
//             int end = meet[1];
//             int duration = end - start;
//             bool found = false;
//             long long earlyEndRoomTime = LLONG_MAX;
//             int earlyEndRoom = 0;
//             for (int room = 0; room < n; room++) {
//                 if (lastAvailableAt[room] <= start) {
//                     lastAvailableAt[room] = end;
//                     roomsUsedCount[room]++;
//                     found = true;
//                     break;
//                 }
//                 if (lastAvailableAt[room] < earlyEndRoomTime) {
//                     earlyEndRoomTime = lastAvailableAt[room];
//                     earlyEndRoom = room;
//                 }
//             }
//             if (!found) {
//                 lastAvailableAt[earlyEndRoom] += duration;
//                 roomsUsedCount[earlyEndRoom]++;
//             }
//         }
//         int resultRoom = -1;
//         int maxUse = 0;
//         for (int room = 0; room < n; room++) {
//             if (roomsUsedCount[room] > maxUse) {
//                 maxUse = roomsUsedCount[room];
//                 resultRoom = room;
//             }
//         }
//         return resultRoom;
//     }
// };
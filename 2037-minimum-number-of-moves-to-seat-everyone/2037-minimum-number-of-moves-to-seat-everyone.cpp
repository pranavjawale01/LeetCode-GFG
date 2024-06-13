class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size();
        int pos_seat[101];
        int pos_stud[101];
        for (int seat : seats) {
            pos_seat[seat]++;
        }
        for (int student : students) {
            pos_stud[student]++;
        }
        int i = 0, j = 0, moves = 0;
        while (i <= 100 && j <= 100) {
            if (pos_seat[i] == 0) {
                i++;
            }
            if (pos_stud[j] == 0) {
                j++;
            }
            if (i <= 100 && j <= 100 && pos_seat[i] != 0 && pos_stud[j] != 0) {
                moves += abs(i - j);
                pos_seat[i]--;
                pos_stud[j]--;
            }
        }
        return moves;
    }
};



// class Solution {
// public:
//     int minMovesToSeat(vector<int>& seats, vector<int>& students) {
//         sort(seats.begin(), seats.end());
//         sort(students.begin(), students.end());
//         int moves = 0;
//         int n = seats.size();
//         for (int i = 0; i < n; i++) {
//             moves += abs(seats[i] - students[i]);
//         }
//         return moves;
//     }
// };
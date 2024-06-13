class Solution {
    public int minMovesToSeat(int[] seats, int[] students) {
        int n = seats.length;
        int[] pos_seat = new int[101];
        int[] pos_stud = new int[101];
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
                moves += Math.abs(i - j);
                pos_seat[i]--;
                pos_stud[j]--;
            }
        }
        return moves;
    }
}



// class Solution {
//     public int minMovesToSeat(int[] seats, int[] students) {
//         Arrays.sort(seats);
//         Arrays.sort(students);
//         int n = seats.length;
//         int moves = 0;
//         for (int i = 0; i < n; i++) {
//             moves += Math.abs(seats[i] - students[i]);
//         }
//         return moves;
//     }
// }
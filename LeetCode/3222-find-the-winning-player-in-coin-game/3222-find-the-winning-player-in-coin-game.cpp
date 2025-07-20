class Solution {
public:
    string solve(int x, int y, string curr) {
        if (x <= 0 || y <= 3) {
            return curr;
        }
        if (curr == "Alice") {
            return solve(x-1, y-4, "Bob");
        }
        return solve(x-1, y-4, "Alice");
    }
    string losingPlayer(int x, int y) {
        return solve(x, y, "Bob");
    }
};



// class Solution {
// public:
//     string losingPlayer(int x, int y) {
//         int count = 0;
//         while (x > 0 && y > 3) {
//             x -= 1;
//             y -= 4;
//             count++;
//         }
//         return count % 2 ? "Alice" : "Bob";
//     }
// };



// class Solution {
// public:
//     string losingPlayer(int x, int y) {
//         int moves = min(x, y / 4);
//         return (moves % 2 == 1) ? "Alice" : "Bob";
//     }
// };
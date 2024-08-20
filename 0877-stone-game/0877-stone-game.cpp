class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};






// Wrong
// class Solution {
// public:
//     bool stoneGame(vector<int>& piles) {
//         int i = 0, j = piles.size() - 1;
//         int alice = 0, bob = 0;
//         bool turn = true;
        
//         while (i <= j) {
//             if (turn) {
//                 if (piles[i] > piles[j]) {
//                     alice += piles[i];
//                     i++;
//                 } else {
//                     alice += piles[j];
//                     j--;
//                 }
//             } else {
//                 if (piles[i] > piles[j]) {
//                     bob += piles[i];
//                     i++;
//                 } else {
//                     bob += piles[j];
//                     j--;
//                 }
//             }
//             turn = !turn;
//         }
        
//         return alice > bob;
//     }
// };
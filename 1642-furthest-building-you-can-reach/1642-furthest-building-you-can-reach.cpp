class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {      
        int n = heights.size();    
        priority_queue<int> pq;        
        int i = 0;
        for(; i < n-1; i++) {
            if (heights[i] >= heights[i+1]) {
                continue;
            }            
            int diff = heights[i+1]-heights[i];
            if (diff <= bricks) {
                bricks -= diff;
                pq.push(diff);
            } else if(ladders > 0) {
                if (!pq.empty()) {
                    int max_bricks_past = pq.top();
                    if (max_bricks_past > diff) {
                        bricks += max_bricks_past;
                        pq.pop();
                        pq.push(diff);
                        bricks -= diff;
                    }
                }
                ladders--;
            } else {
                break;
            }
        }
        return i;
    }
};

// class Solution {
// public:
//     int n;
//     vector<vector<int>> memo;
//     int solve(int i,vector<int>& heights, int bricks, int ladders) {
//         if (i == n - 1) {
//             return 0;
//         }
//         if (memo[bricks][ladders] != -1) {
//             return memo[bricks][ladders];
//         }
//         if (heights[i+1] <= heights[i]) {
//             return memo[bricks][ladders] = 1 + solve(i+1, heights, bricks, ladders);
//         } else {
//             int useBrick = 0, useLadder = 0;
//             int diff = heights[i+1] - heights[i];
//             if (bricks >= diff) {
//                 useBrick = 1 + solve(i+1, heights, bricks - diff, ladders);
//             } 
//             if (ladders > 0) {
//                 useLadder = 1 + solve(i+1, heights, bricks, ladders-1);
//             }
//             return memo[bricks][ladders] = max(useBrick, useLadder);
//         }
//     }
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
//         n = heights.size();
//         memo = vector<vector<int>>(bricks+1, vector<int>(ladders+1, -1));
//         return solve(0, heights, bricks, ladders);
//     }
// };
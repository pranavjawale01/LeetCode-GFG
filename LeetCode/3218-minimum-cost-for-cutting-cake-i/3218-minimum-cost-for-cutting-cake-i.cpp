class Solution {
public:
    int minimumCost(int m, int n, std::vector<int>& horizontalCut, std::vector<int>& verticalCut) {
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());
        
        long long h = 0, v = 0;
        long long verticalPieces = 1, horizontalPieces = 1;
        long long totalCost = 0;
        const int MOD = 1e9 + 7;
        
        while (h < horizontalCut.size() && v < verticalCut.size()) {
            if (horizontalCut[h] > verticalCut[v]) {
                totalCost = (totalCost + (long long) horizontalCut[h] * verticalPieces) % MOD;
                horizontalPieces++;
                h++;
            } else {
                totalCost = (totalCost + (long long) verticalCut[v] * horizontalPieces) % MOD;
                verticalPieces++;
                v++;
            }
        }
        
        while (h < horizontalCut.size()) {
            totalCost = (totalCost + (long long) horizontalCut[h] * verticalPieces) % MOD;
            h++;
        }
        
        while (v < verticalCut.size()) {
            totalCost = (totalCost + (long long) verticalCut[v] * horizontalPieces) % MOD;
            v++;
        }
        
        return totalCost;
    }
};
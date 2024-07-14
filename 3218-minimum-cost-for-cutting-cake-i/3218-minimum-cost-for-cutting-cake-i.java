class Solution {
    public int minimumCost(int m, int n, int[] horizontalCut, int[] verticalCut) {
        Arrays.sort(horizontalCut);
        Arrays.sort(verticalCut);

        for (int i = 0; i < horizontalCut.length / 2; i++) {
            horizontalCut[i] = horizontalCut[i] ^ horizontalCut[horizontalCut.length - 1 - i];
            horizontalCut[horizontalCut.length - 1 - i] = horizontalCut[i] ^ horizontalCut[horizontalCut.length - 1 - i];
            horizontalCut[i] = horizontalCut[i] ^ horizontalCut[horizontalCut.length - 1 - i];
        }

        for (int i = 0; i < verticalCut.length / 2; i++) {
            verticalCut[i] = verticalCut[i] ^ verticalCut[verticalCut.length - 1 - i];
            verticalCut[verticalCut.length - 1 - i] = verticalCut[i] ^ verticalCut[verticalCut.length - 1 - i];
            verticalCut[i] = verticalCut[i] ^ verticalCut[verticalCut.length - 1 - i];
        }
        
        int h = 0, v = 0;
        long verticalPieces = 1, horizontalPieces = 1;
        long totalCost = 0;
        final int MOD = 1000000007;
        
        while (h < horizontalCut.length && v < verticalCut.length) {
            if (horizontalCut[h] > verticalCut[v]) {
                totalCost = (totalCost + (long) horizontalCut[h] * verticalPieces) % MOD;
                horizontalPieces++;
                h++;
            } else {
                totalCost = (totalCost + (long) verticalCut[v] * horizontalPieces) % MOD;
                verticalPieces++;
                v++;
            }
        }
        
        while (h < horizontalCut.length) {
            totalCost = (totalCost + (long) horizontalCut[h] * verticalPieces) % MOD;
            h++;
        }
        
        while (v < verticalCut.length) {
            totalCost = (totalCost + (long) verticalCut[v] * horizontalPieces) % MOD;
            v++;
        }
        
        return (int) totalCost;
    }
}
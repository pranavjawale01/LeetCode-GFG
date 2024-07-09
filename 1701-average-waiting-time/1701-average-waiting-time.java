class Solution {
    public double averageWaitingTime(int[][] customers) {
        double waitTime = 0;
        int currTime = 0;
        int n = customers.length;
        for (int[] x : customers) {
            int arrival = x[0];
            int cookTime = x[1];
            if (currTime < arrival) {
                currTime = arrival;
            }
            int wait = currTime + cookTime - arrival;
            waitTime += wait;
            currTime += cookTime;
        }
        return waitTime / n;
    }
}
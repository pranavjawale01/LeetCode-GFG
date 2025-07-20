class MyCalendarTwo {
    private List<int[]> doubleBooking;
    private List<int[]> singleBooking;

    public MyCalendarTwo() {
        doubleBooking = new ArrayList<>();
        singleBooking = new ArrayList<>();
    }
    
    private boolean checkBooking(int s1, int e1, int s2, int e2) {
        return Math.max(s1, s2) < Math.min(e1, e2);
    }

    private int[] findOverlap(int s1, int e1, int s2, int e2) {
        return new int[]{Math.max(s1, s2), Math.min(e1, e2)};
    }

    public boolean book(int start, int end) {
        for (int[] x : doubleBooking) {
            if (checkBooking(x[0], x[1], start, end)) {
                return false;
            }
        }
        for (int[] x : singleBooking) {
            if (checkBooking(x[0], x[1], start, end)) {
                doubleBooking.add(findOverlap(x[0], x[1], start, end));
            }
        }
        singleBooking.add(new int[]{start, end});
        return true;
    }
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * boolean param_1 = obj.book(start,end);
 */
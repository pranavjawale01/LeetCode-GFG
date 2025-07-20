class MyCalendar {
    private TreeSet<int[]> st;

    public MyCalendar() {
        st = new TreeSet<>((a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
    }
    
    public boolean book(int start, int end) {
        int[] next = st.higher(new int[]{start, end});
        if (next != null && next[1] < end) {
            return false;
        }
        st.add(new int[]{end, start});
        return true;
    }
}





// class MyCalendar {
//     private TreeSet<int[]> st;

//     public MyCalendar() {
//         st = new TreeSet<>((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
//     }
    
//     public boolean book(int start, int end) {
//         int[] x = {start, end};
//         int[] nxt = st.ceiling(x);
//         if (nxt != null && nxt[0] < end) {
//             return false;
//         }
//         int[] prev = st.floor(x);
//         if (prev != null && prev[1] > start) {
//             return false;
//         }
//         st.add(x);
//         return true;
//     }
// }







// class MyCalendar {
//     private List<int[]> cal;

//     public MyCalendar() {
//         cal = new ArrayList<>();
//     }
    
//     public boolean book(int start, int end) {
//         for (int[] x : cal) {
//             if (end > x[0] && start < x[1]) {
//                 return false;
//             }
//         }
//         cal.add(new int[]{start, end});
//         return true;
//     }
// }



/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */
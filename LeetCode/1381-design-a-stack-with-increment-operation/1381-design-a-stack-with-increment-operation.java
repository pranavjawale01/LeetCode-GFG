class CustomStack {
    private List<Integer> st;
    private int size;

    public CustomStack(int maxSize) {
        st = new ArrayList<>();
        size = maxSize;
    }
    
    public void push(int x) {
        if (st.size() < size) {
            st.add(x);
        }
    }
    
    public int pop() {
        if (st.isEmpty()) {
            return -1;
        }
        return st.remove(st.size() - 1);
    }
    
    public void increment(int k, int val) {
        k = Math.min(k, st.size());
        for (int i = 0; i < k; i++) {
            st.set(i, st.get(i) + val);
        }
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */
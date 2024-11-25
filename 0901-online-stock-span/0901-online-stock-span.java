class StockSpanner {
    Stack<Pair<Integer, Integer>> st = new Stack<>();

    public StockSpanner() {
        
    }
    
    public int next(int price) {
         int span = 1;
        while (!st.isEmpty() && st.peek().getKey() <= price) {
            span += st.peek().getValue();
            st.pop();
        }
        st.push(new Pair<>(price, span));
        return span;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
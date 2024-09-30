class CustomStack {
public:
    vector<int> stack;
    int stSize;

    CustomStack(int maxSize) {
        stSize = maxSize;
    }
    
    void push(int x) {
        if (stack.size() < stSize) {
            stack.push_back(x);
        }
    }
    
    int pop() {
        if (stack.empty()) {
            return -1;
        }
        int a = stack.back();
        stack.pop_back();
        return a;
    }
    
    void increment(int k, int val) {
        k = min(k, (int)stack.size());
        for (int i = 0; i < k; i++) {
            stack[i] += val;
        }
    }
};


/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
typedef pair<int, int> p;
class MyCalendar {
public:
    vector<p> cal;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (int i = 0; i < cal.size(); i++) {
            p curr = cal[i];
            if (!(end <= curr.first || start >= curr.second)) {
                return false;
            }
        }
        cal.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
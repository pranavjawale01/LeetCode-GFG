class MyCalendarTwo {
public:
    vector<pair<int, int>> doubleBooking;
    vector<pair<int, int>> singleBooking;

    bool checkBooking(int s1, int e1, int s2, int e2) {
        return max(s1, s2) < min(e1, e2);
    }

    pair<int, int> findOverlap(int s1, int e1, int s2, int e2) {
        return {max(s1, s2), min(e1, e2)};
    }

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (pair<int, int> x : doubleBooking) {
            if (checkBooking(x.first, x.second, start, end)) {
                return false;
            }
        }
        for (pair<int, int> x : singleBooking) {
            if (checkBooking(x.first, x.second, start, end)) {
                doubleBooking.push_back(findOverlap(x.first, x.second, start, end));
            }
        }
        singleBooking.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
class MyCalendar {
public:
    set<pair<int, int>> st;

    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = st.upper_bound({start, end});
        if (it != st.end() && end > it->second) {
            return false;
        }
        st.insert({end, start});
        return true;
    }
};








// class MyCalendar {
// public:
//     set<pair<int, int>> st;
//     MyCalendar() {
        
//     }
    
//     bool book(int start, int end) {
//         auto it = st.lower_bound({start, end});
//         if (it != st.end() && it->first < end) {
//             return false;
//         }
//         if (it != st.begin()) {
//             auto prevIt = prev(it);
//             if (start < prevIt->second) {
//                 return false;
//             }
//         }
//         st.insert({start, end});
//         return true;
//     }
// };








// typedef pair<int, int> p;
// class MyCalendar {
// public:
//     vector<p> cal;
//     MyCalendar() {
        
//     }
    
//     bool book(int start, int end) {
//         for (int i = 0; i < cal.size(); i++) {
//             p curr = cal[i];
//             if (!(end <= curr.first || start >= curr.second)) {
//                 return false;
//             }
//         }
//         cal.push_back({start, end});
//         return true;
//     }
// }





/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
from sortedcontainers import SortedList

class MyCalendar:

    def __init__(self):
        self.st= SortedList()

    def book(self, start: int, end: int) -> bool:
        idx = self.st.bisect_left((start, end))
        if idx < len(self.st) and self.st[idx][0] < end:
            return False
        if idx > 0 and self.st[idx-1][1] > start:
            return False
        self.st.add((start, end))
        return True






# class MyCalendar:

#     def __init__(self):
#         self.cal = []        

#     def book(self, start: int, end: int) -> bool:
#         for x in self.cal:
#             if end > x[0] and start < x[1]:
#                 return False
#         self.cal.append([start, end])
#         return True







# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
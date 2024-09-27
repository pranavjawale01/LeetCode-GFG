class MyCalendarTwo:
    def __init__(self):
        self.doubleBooking = []
        self.singleBooking = []

    def check_booking(self, s1: int, e1: int, s2: int, e2: int) -> bool:
        return max(s1, s2) < min(e1, e2)

    def find_overlap(self, s1: int, e1: int, s2: int, e2: int) -> tuple:
        return (max(s1, s2), min(e1, e2))

    def book(self, start: int, end: int) -> bool:
        for x in self.doubleBooking:
            if self.check_booking(x[0], x[1], start, end):
                return False
        
        for x in self.singleBooking:
            if self.check_booking(x[0], x[1], start, end):
                self.doubleBooking.append(self.find_overlap(x[0], x[1], start, end))
        
        self.singleBooking.append((start, end))
        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)
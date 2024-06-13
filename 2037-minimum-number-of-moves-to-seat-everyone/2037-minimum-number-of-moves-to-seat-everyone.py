class Solution:
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        n = len(seats)
        position_seat = [0] * 101
        position_stud = [0] * 101

        for pos in seats:
            position_seat[pos] += 1
        for pos in students:
            position_stud[pos] += 1
        i , j = 0 , 0
        moves = 0
        while i <= 100 and j <= 100:
            if position_seat[i] == 0:
                i += 1
            if position_stud[j] == 0:
                j += 1
            if i <= 100 and j <= 100 and position_seat[i] != 0 and position_stud[j] != 0:
                moves += abs(i - j)
                position_seat[i] -= 1
                position_stud[j] -= 1
        return moves



# class Solution:
#     def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
#         seats.sort()
#         students.sort()
#         n = len(seats)
#         moves = 0
#         for i in range(n):
#             moves += abs(students[i] - seats[i])
#         return moves
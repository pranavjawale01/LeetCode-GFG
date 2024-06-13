class Solution:
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        seats.sort()
        students.sort()
        n = len(seats)
        moves = 0
        for i in range(n):
            moves += abs(students[i] - seats[i])
        return moves
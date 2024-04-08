class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        arr = [0] * 2
        n = len(students)
        for num in students:
            if num == 1:
                arr[1] += 1
        arr[0] = n - arr[1]
        for i in range(n):
            sand = sandwiches[i]
            if arr[sand] == 0:
                return n - i
            arr[sand] -= 1
        return 0
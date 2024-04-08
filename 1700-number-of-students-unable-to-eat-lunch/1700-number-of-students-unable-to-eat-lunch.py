class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        que = deque()
        st = []
        n = len(students)
        for i in range(n):
            st.append(sandwiches[n - i - 1])
            que.append(students[i])
        lastServed = 0
        while que and lastServed < len(que):
            if st[-1] == que[0]:
                st.pop()
                que.popleft()
                lastServed = 0
            else:
                que.append(que[0])
                que.popleft()
                lastServed += 1
        return len(que)
                

# class Solution:
#     def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
#         arr = [0] * 2
#         n = len(students)
#         for num in students:
#             if num == 1:
#                 arr[1] += 1
#         arr[0] = n - arr[1]
#         for i in range(n):
#             sand = sandwiches[i]
#             if arr[sand] == 0:
#                 return n - i
#             arr[sand] -= 1
#         return 0
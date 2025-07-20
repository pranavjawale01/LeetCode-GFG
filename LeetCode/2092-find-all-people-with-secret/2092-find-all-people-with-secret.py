class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:

        graph = collections.defaultdict(list)
        for meeting in meetings:
            person1, person2, time = meeting
            graph[person2].append((time, person1))
            graph[person1].append((time, person2))

        pq = [(0, 0), (0, firstPerson)]
        heapq.heapify(pq)

        visited = [False] * n

        while pq:
            time, person = heapq.heappop(pq)
            if visited[person]:
                continue
            visited[person] = True
            for t, nextPerson in graph.get(person, []):
                if not visited[nextPerson] and t >= time:
                    heapq.heappush(pq, (t, nextPerson))

        ans = []
        for i in range(n):
            if visited[i]:
                ans.append(i)
        return ans
class Solution:
    def leftmostBuildingQueries(self, heights: List[int], queries: List[List[int]]) -> List[int]:
        n = len(heights)
        queryCount = len(queries)
        result = [-1] * queryCount
        deferredQueries = [[] for _ in range(n)]
        minHeap = []

        for queryIndex in range(queryCount):
            aliceStart, bobStart = queries[queryIndex]

            if aliceStart == bobStart:
                result[queryIndex] = aliceStart
            elif aliceStart < bobStart and heights[aliceStart] < heights[bobStart]:
                result[queryIndex] = bobStart
            elif aliceStart > bobStart and heights[aliceStart] > heights[bobStart]:
                result[queryIndex] = aliceStart
            else:
                maxHeight = max(heights[aliceStart], heights[bobStart])
                maxIndex = max(aliceStart, bobStart)
                deferredQueries[maxIndex].append((maxHeight, queryIndex))

        for currentBuilding in range(n):
            while minHeap and minHeap[0][0] < heights[currentBuilding]:
                queryIndex = heapq.heappop(minHeap)[1]
                result[queryIndex] = currentBuilding

            for query in deferredQueries[currentBuilding]:
                heapq.heappush(minHeap, query)

        return result
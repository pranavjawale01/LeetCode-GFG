class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        n = len(customers)
        waitTime = 0
        currTime = 0
        for x in customers:
            arrival = x[0]
            cookTime = x[1]
            if currTime < arrival:
                currTime = arrival
            wait = currTime + cookTime - arrival
            currTime += cookTime
            waitTime += wait
        return waitTime / n
class Solution:
    def canAliceWin(self, nums: List[int]) -> bool:
        singleNum = 0
        doubleNum = 0
        for x in nums:
            if x <= 9:
                singleNum += x
            else:
                doubleNum += x
        if singleNum == doubleNum:
            return False
        return True
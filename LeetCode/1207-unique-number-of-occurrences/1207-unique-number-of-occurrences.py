class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        setList = set()
        mapList = {}
        
        for x in arr:
            mapList[x] = mapList.get(x, 0)+1
        
        for x in mapList.values():
            if x in setList:
                return False
            setList.add(x)
            
        return True
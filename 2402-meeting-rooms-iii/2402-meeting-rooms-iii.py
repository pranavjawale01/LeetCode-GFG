class Solution:
    
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        ans={}
        meetings.sort(key=lambda x: x[0])
        rooms=[0]*n
        for a,b in meetings:
            mini=math.inf
            p=-1
            flag=0
            for j in range(len(rooms)):
                if rooms[j]<=a:
                    rooms[j]=b
                    if j in ans:
                        ans[j]+=1
                    else:
                        ans[j]=1
                    flag=1
                    break
                else:
                    if mini > rooms[j]:
                        mini=rooms[j]
                        p=j
            if flag==0:
                rooms[p]=rooms[p] + b-a
                if p in ans:
                    ans[p]+=1
                else:
                    ans[p]=1
        res=sorted(ans.items(),key=lambda x:x[1],reverse=True)
        print(ans)
        return res[0][0]         
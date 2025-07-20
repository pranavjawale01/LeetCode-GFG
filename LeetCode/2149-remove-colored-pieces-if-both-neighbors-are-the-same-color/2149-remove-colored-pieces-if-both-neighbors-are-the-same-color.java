class Solution {
    public boolean winnerOfGame(String colors) {
        int n = colors.length(), c1=0, c2=0;
        for(int i=1;i<n-1;i++)
        {
            if(colors.charAt(i) == colors.charAt(i-1) && colors.charAt(i) == colors.charAt(i+1))
            {
                if(colors.charAt(i)=='A')
                {
                    c1 += 1;
                }
                if(colors.charAt(i)=='B')
                {
                    c2 += 1;
                }
            }
        }
        return c1 > c2;
    }
}
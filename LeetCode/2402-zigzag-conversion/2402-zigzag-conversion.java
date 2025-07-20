public class Solution {
    public String convert(String s, int nRows) {
        if(s == null || nRows == 1) return s;
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < nRows; ++i){
            for(int j = i; j < s.length(); j += nRows * 2 - 2){
                sb.append(s.charAt(j));
                if(i > 0 || i < nRows - 1 && j + (nRows - (i + 1) % nRows) * 2 < s.length()){
                        sb.append(s.charAt(j + (nRows - (i + 1)  % nRows) * 2));
                    }
                }
            }
        }
        return sb.toString();
    }
}
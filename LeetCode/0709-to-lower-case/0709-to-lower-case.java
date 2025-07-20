class Solution {
    public String toLowerCase(String s) {
        StringBuilder str = new StringBuilder();
        for (char c : s.toCharArray()) {
            str.append(Character.toLowerCase(c));
        }
        return str.toString();
    }
}


// class Solution {
//     public String toLowerCase(String s) {
//         return s.toLowerCase();
//     }
// }
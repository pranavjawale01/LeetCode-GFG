class Solution {
    public String intToBinary(int n) {
        StringBuilder sb = new StringBuilder();
        boolean leadingZero = true;
        for (int i = 31; i >= 0; i--) {
            if ((n & (1 << i)) != 0) {
                sb.append('1');
                leadingZero = false;
            } else if (!leadingZero) {
                sb.append('0');
            }
        } 
        return sb.length() == 0 ? "0" : sb.toString();
    }

    public String convertDateToBinary(String date) {
        String yearStr = date.substring(0, 4);
        String monthStr = date.substring(5, 7);
        String dayStr = date.substring(8, 10);

        int yearInt = Integer.parseInt(yearStr);
        int monthInt = Integer.parseInt(monthStr);
        int dayInt = Integer.parseInt(dayStr);

        String yearBinary = intToBinary(yearInt);
        String monthBinary = intToBinary(monthInt);
        String dayBinary = intToBinary(dayInt);

        return yearBinary + "-" + monthBinary + "-" + dayBinary;
    }
}
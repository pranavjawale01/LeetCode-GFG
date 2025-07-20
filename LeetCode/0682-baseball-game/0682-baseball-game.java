class Solution {
    public int calPoints(String[] operations) {
        List<Integer> score = new ArrayList<>();
        for (String op : operations) {
            if (op.equals("C")) {
                score.remove(score.size() - 1);
            } else if (op.equals("D")) {
                score.add(score.get(score.size() - 1) * 2);
            } else if (op.equals("+")) {
                int n = score.size();
                score.add(score.get(n - 1) + score.get(n - 2));
            } else {
                score.add(Integer.parseInt(op));
            }
        }
        int sum = 0;
        for (int s : score) {
            sum += s;
        }
        return sum;
    }
}
class NumberContainers {
    private Map<Integer, Integer> mpIdxNum;
    private Map<Integer, TreeSet<Integer>> mpNumIdx;

    public NumberContainers() {
        mpIdxNum = new HashMap<>();
        mpNumIdx = new HashMap<>();
    }

    public void change(int index, int number) {
        if (mpIdxNum.containsKey(index)) {
            int prevNumber = mpIdxNum.get(index);
            mpNumIdx.get(prevNumber).remove(index);
            if (mpNumIdx.get(prevNumber).isEmpty()) {
                mpNumIdx.remove(prevNumber);
            }
        }
        mpIdxNum.put(index, number);
        mpNumIdx.putIfAbsent(number, new TreeSet<>());
        mpNumIdx.get(number).add(index);
    }

    public int find(int number) {
        if (mpNumIdx.containsKey(number)) {
            return mpNumIdx.get(number).first();
        }
        return -1;
    }
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.change(index,number);
 * int param_2 = obj.find(number);
 */
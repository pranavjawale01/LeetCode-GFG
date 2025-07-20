class SnapshotArray {
    private int snapId;
    private Map<Integer, TreeMap<Integer, Integer>> data;

    public SnapshotArray(int length) {
        snapId = 0;
        data = new HashMap<>();
        for (int i = 0; i < length; i++) {
            data.put(i, new TreeMap<>());
            data.get(i).put(0, 0);
        }
    }

    public void set(int index, int val) {
        data.get(index).put(snapId, val);
    }

    public int snap() {
        return snapId++;
    }

    public int get(int index, int snap_id) {
        TreeMap<Integer, Integer> snapMap = data.get(index);
        return snapMap.floorEntry(snap_id).getValue();
    }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray obj = new SnapshotArray(length);
 * obj.set(index,val);
 * int param_2 = obj.snap();
 * int param_3 = obj.get(index,snap_id);
 */
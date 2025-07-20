class SnapshotArray:
    def __init__(self, length: int):
        self.snap_id = 0
        self.data = [{} for _ in range(length)]
        for i in range(length):
            self.data[i][0] = 0

    def set(self, index: int, val: int) -> None:
        self.data[index][self.snap_id] = val

    def snap(self) -> int:
        self.snap_id += 1
        return self.snap_id - 1

    def get(self, index: int, snap_id: int) -> int:
        snaps = self.data[index]
        while snap_id not in snaps and snap_id >= 0:
            snap_id -= 1
        return snaps.get(snap_id, 0)

# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index, val)
# param_2 = obj.snap()
# param_3 = obj.get(index, snap_id)
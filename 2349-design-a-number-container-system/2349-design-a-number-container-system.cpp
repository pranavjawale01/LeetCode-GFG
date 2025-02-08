class NumberContainers {
public:
    NumberContainers() {
        
    }

    unordered_map<int, int> mpIdxNum;
    unordered_map<int, set<int>> mpNumIdx;
    
    void change(int index, int number) {
        if (mpIdxNum.find(index) == mpIdxNum.end()) {
            mpIdxNum[index] = number;
            mpNumIdx[number].insert(index);
        } else {
            int prevNumber = mpIdxNum[index];
            mpNumIdx[prevNumber].erase(index);
            if (mpNumIdx[prevNumber].empty()) {
                mpNumIdx.erase(prevNumber);
            }
            mpIdxNum[index] = number;
            mpNumIdx[number].insert(index);
        }
    }
    
    int find(int number) {
        if (mpNumIdx.find(number) != mpNumIdx.end()) {
            return *mpNumIdx[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
class MyCircularDeque {
private:
    vector<int> deque;
    int front, rear, capacity, count;
    
public:
    MyCircularDeque(int k) {
        capacity = k;
        deque.resize(k);
        front = 0;
        rear = 0;
        count = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        deque[front] = value;
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        deque[rear] = value;
        rear = (rear + 1) % capacity;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        count--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        count--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return deque[front];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return deque[(rear - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};
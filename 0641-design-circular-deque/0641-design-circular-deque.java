class MyCircularDeque {
    private int[] deque;
    private int front, rear, capacity, count;

    public MyCircularDeque(int k) {
        capacity = k;
        deque = new int[k];
        front = 0;
        rear = 0;
        count = 0;
    }

    public boolean insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        deque[front] = value;
        count++;
        return true;
    }

    public boolean insertLast(int value) {
        if (isFull()) return false;
        deque[rear] = value;
        rear = (rear + 1) % capacity;
        count++;
        return true;
    }

    public boolean deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        count--;
        return true;
    }

    public boolean deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        count--;
        return true;
    }

    public int getFront() {
        if (isEmpty()) return -1;
        return deque[front];
    }

    public int getRear() {
        if (isEmpty()) return -1;
        return deque[(rear - 1 + capacity) % capacity];
    }

    public boolean isEmpty() {
        return count == 0;
    }

    public boolean isFull() {
        return count == capacity;
    }
}
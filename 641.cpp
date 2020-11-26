class MyCircularDeque {
public:
    int *data;
    int front, rear;
    int size;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = k + 1;
        data = new int[k + 1];
        for (int i = 0; i < k + 1; ++i) {
            data[i] = -1;
        }
        front = 0;
        rear = 1;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        } else {
            data[front] = value;
            front = (front - 1 + size) % size;
            return true;
        }
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        } else {
            data[rear] = value;
            rear = (rear + 1) % size;
            return true;
        }
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        } else {
            data[(front + 1) % size] = -1;
            front = (front + 1) % size;
            return true;
        }
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        } else {
            data[(rear - 1 + size) % size] = -1;
            rear = (rear - 1 + size) % size;
            return true;
        }
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return data[(front + 1) % size];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return data[(rear - 1 + size) % size];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return (front + 1) % size == rear;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return front == rear % size;
    }
};

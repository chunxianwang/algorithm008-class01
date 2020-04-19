/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
class MyCircularDeque {
private:
    vector<int> arr;
    int front;
    int rear;
    int capacity;//实际队列的长度

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        capacity = k + 1; //在存放数据的有效元素基础上增加一个无效元素
        arr.assign(capacity, 0);
        front = 0;
        rear = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    //考虑front指向队列最左端的情况
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 +capacity) % capacity;
        arr[front] = value;
        return true;

    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    //考虑rear指向队列最右端（有效元素）的情况
    bool insertLast(int value) {
        if (isFull()) return false;
        arr[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    //考虑front指向最右端有效元素的情况
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    //考虑rear指向最左端有效元素的情况
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 +capacity) % capacity;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        return arr[(rear - 1 +capacity) % capacity];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return front == rear;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        //循环数据结构中的经典做法
        return (rear + 1) % capacity == front;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end


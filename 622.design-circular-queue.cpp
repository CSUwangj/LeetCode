/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
class MyCircularQueue {
  vector<int> container;
  int begin;
  int size;
  int capacity;
public:
  MyCircularQueue(int k): capacity(k) {
    container.resize(k);
    begin = 0;
    size = 0;
  }
  
  bool enQueue(int value) {
    if(size == capacity) return false;
    container[(begin + size) % capacity] = value;
    size += 1;
    return true;
  }
  
  bool deQueue() {
    if(!size) return false;
    begin = (begin + 1) % capacity;
    size -= 1;
    return true;
  }
  
  int Front() {
    if(!size) return -1;
    return container[begin];
  }
  
  int Rear() {
    if(!size) return -1;
    return container[(begin + size - 1) % capacity];
  }
  
  bool isEmpty() {
    return size == 0;
  }
  
  bool isFull() {
    return size == capacity; 
  }
};

// Accepted
// 58/58 cases passed (16 ms)
// Your runtime beats 97.99 % of cpp submissions
// Your memory usage beats 40.24 % of cpp submissions (16.9 MB)
// @lc code=end


/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack {
  queue<int> container;
public:
  /** Initialize your data structure here. */
  MyStack() { }
  
  /** Push element x onto stack. */
  void push(int x) {
    int sz = container.size();
    container.push(x);
    while(sz--) {
      container.push(container.front());
      container.pop();
    }
  }
  
  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int val = container.front();
    container.pop();
    return val;
  }
  
  /** Get the top element. */
  int top() {
    return container.front();
  }
  
  /** Returns whether the stack is empty. */
  bool empty() {
    return container.empty();
  }
};

// Accepted
// 16/16 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 98.89 % of cpp submissions (6.7 MB)
// @lc code=end


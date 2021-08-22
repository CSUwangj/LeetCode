/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class MyQueue {
  vector<int> out;
  vector<int> in;

  void refill() {
    if(out.size()) return;
    while(in.size()) {
      out.push_back(in.back());
      in.pop_back();
    }
  }
public:
  /** Initialize your data structure here. */
  MyQueue() {}
  
  /** Push element x to the back of queue. */
  void push(int x) {
    in.push_back(x);
  }
  
  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    refill();
    int val = out.back();
    out.pop_back();
    return val;
  }
  
  /** Get the front element. */
  int peek() {
    refill();
    return out.back();
  }
  
  /** Returns whether the queue is empty. */
  bool empty() {
    return out.empty() && in.empty();
  }
};

// Accepted
// 21/21 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 45.12 % of cpp submissions (7.1 MB)
// @lc code=end


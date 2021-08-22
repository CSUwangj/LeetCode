/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class MinStack {
  vector<int> st;
  vector<int> minSt;
public:
  /** initialize your data structure here. */
  MinStack(){}
  
  void push(int val) {
    st.push_back(val);
    if(minSt.empty() || val <= minSt.back()) {
      minSt.push_back(val);
    }
  }
  
  void pop() {
    if(st.back() == minSt.back()) {
      minSt.pop_back();
    }
    st.pop_back();
  }
  
  int top() {
    return st.back();
  }
  
  int getMin() {
    return minSt.back();
  }
};

// Accepted
// 31/31 cases passed (12 ms)
// Your runtime beats 99.73 % of cpp submissions
// Your memory usage beats 33.29 % of cpp submissions (16.5 MB)
// @lc code=end


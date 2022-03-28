/*
 * @lc app=leetcode id=895 lang=cpp
 *
 * [895] Maximum Frequency Stack
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class FreqStack {
  vector<vector<int>> stack;
  unordered_map<int, int> count;
  int maxCount;
public:
  FreqStack(): maxCount(0) {}
  
  void push(int val) {
    if(maxCount == count[val]) {
      stack.push_back({});
    }
    stack[count[val]].push_back(val);
    count[val] += 1;
    maxCount = max(maxCount, count[val]);
  }
  
  int pop() {
    int val = stack.back().back();
    count[val] -= 1;
    stack.back().pop_back();
    if(stack.back().empty()) {
      stack.pop_back();
      maxCount -= 1;
    }
    return val;
  }
};

// Accepted
// 37/37 cases passed (196 ms)
// Your runtime beats 82.29 % of cpp submissions
// Your memory usage beats 82.96 % of cpp submissions (79.9 MB)
// @lc code=end

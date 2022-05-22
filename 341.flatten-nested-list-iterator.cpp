/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

// @lc code=start
class NestedIterator {
  vector<int> integers;
  int len;
  int i;
  void solve(NestedInteger &nestedInt) {
    if(nestedInt.isInteger()) {
      integers.push_back(nestedInt.getInteger());
      return;
    }
    for(auto &l : nestedInt.getList()) {
      solve(l);
    }
  }
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    for(auto &nestedInt : nestedList) solve(nestedInt);
    len = integers.size();
    i = 0;
  }

  int next() {
    return integers[i++];
  }

  bool hasNext() {
    return i != len;
  }
};

// Accepted
// 43/43 cases passed (14 ms)
// Your runtime beats 84.39 % of cpp submissions
// Your memory usage beats 56.47 % of cpp submissions (13.1 MB)
// @lc code=end


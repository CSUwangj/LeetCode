/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class MedianFinder {
  priority_queue<int> greaterQ;
  priority_queue<int, vector<int>, greater<int>> lessQ;
public:
  /** initialize your data structure here. */
  MedianFinder() { }
  
  void addNum(int num) {
    if(greaterQ.size() && greaterQ.top() <= num) {
      lessQ.push(num);
    } else {
      if(greaterQ.size()) {
        lessQ.push(greaterQ.top());
        greaterQ.pop();
      }
      greaterQ.push(num);
    }
    if(lessQ.size() > greaterQ.size()) {
      greaterQ.push(lessQ.top());
      lessQ.pop();
    }
  }
  
  double findMedian() {
    if(greaterQ.size() > lessQ.size()) {
      return greaterQ.top();
    } else {
      return (greaterQ.top() + lessQ.top()) / 2.0;
    }
  }
};

// Accepted
// 21/21 cases passed (493 ms)
// Your runtime beats 77.43 % of cpp submissions
// Your memory usage beats 99.79 % of cpp submissions (116.4 MB)
// @lc code=end


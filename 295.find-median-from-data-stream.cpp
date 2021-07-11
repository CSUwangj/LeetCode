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
// 18/18 cases passed (180 ms)
// Your runtime beats 15.97 % of cpp submissions
// Your memory usage beats 20.18 % of cpp submissions (47.1 MB)

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end


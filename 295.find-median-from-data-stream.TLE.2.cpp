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
  multiset<int> st;
public:
  /** initialize your data structure here. */
  MedianFinder() { }
  
  void addNum(int num) {
    st.insert(num);
  }
  
  double findMedian() {
    auto it = st.begin();
    advance(it, st.size() / 2);
    if(st.size() & 1) {
      return *it;
    } else {
      auto it2 = it;
      --it2;
      return (*it + *it2) / 2.0;
    }
  }
};

// Time Limit Exceeded
// 19/21 cases passed (N/A)
// @lc code=end


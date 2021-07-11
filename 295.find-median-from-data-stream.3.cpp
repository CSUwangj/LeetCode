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

// Accepted
// 18/18 cases passed (1716 ms)
// Your runtime beats 5.03 % of cpp submissions
// Your memory usage beats 8.33 % of cpp submissions (49.6 MB)
// @lc code=end


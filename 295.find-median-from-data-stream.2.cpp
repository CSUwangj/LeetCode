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
#define lowbit(x) (x & (-x))
const int SIZE = 200002;
int BITS[SIZE];
void add(int x) {
  while(x < SIZE) {
    BITS[x] += 1;
    x += lowbit(x);
  }
}
int sum(int x) {
  int result = 0;
  while(x) {
    result += BITS[x];
    x -= lowbit(x);
  }
  return result;
}
class MedianFinder {
  int size = 0;
  int low = INT_MAX;
  int high = INT_MIN;
  int get(int cnt) {
    int start = low;
    int end = high;
    while(start < end) {
      int mid = (start + end) >> 1;
      if(sum(mid) < cnt) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }
    return start;
  }
public:
  /** initialize your data structure here. */
  MedianFinder() { 
    memset(BITS, 0, sizeof(BITS));
  }
  
  void addNum(int num) {
    low = min(low, num + 100001);
    high = max(high, num + 100001);
    size += 1;
    add(num + 100001);
  }
  
  double findMedian() {
    if(low == high) return low - 100001;
    if(size & 1) return get(size / 2 + 1) - 100001;
    return (get(size / 2) + get(size / 2 + 1)) / 2.0 - 100001;
  }
};

// 21/21 cases passed (363 ms)
// Your runtime beats 90.42 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (115.3 MB)
// @lc code=end


/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class KthLargest {
  priority_queue<int, vector<int>, greater<int>> pq;
public:
  KthLargest(int k, vector<int>& nums) {
    int len = nums.size();
    for(int i = 0; i < len && i < k; ++i) {
      pq.push(nums[i]);
    }
    for(int i = k; i < len; ++i) {
      pq.push(nums[i]);
      pq.pop();
    }
    if(len < k) pq.push(INT_MIN);
  }
  
  int add(int val) {
    pq.push(val);
    pq.pop();
    return pq.top();
  }
};

// Accepted
// 10/10 cases passed (20 ms)
// Your runtime beats 99.9 % of cpp submissions
// Your memory usage beats 17.93 % of cpp submissions (19.9 MB)
// @lc code=end

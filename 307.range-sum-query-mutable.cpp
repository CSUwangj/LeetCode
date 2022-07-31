/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
class NumArray {
  vector<int> &_nums;
  int len;
  int lazy[30000 << 2] = {};
  int sum[30000 << 2] = {};

  int opL;
  int opR;
  void build(int l, int r, int o = 0) {
    if(l == r) sum[o] = _nums[l];
    else {
      int m = (l + r) >> 1;
      build(l, m, o * 2 + 1);
      build(m + 1, r, o * 2 + 2);
      sum[o] = sum[o * 2 + 1] + sum[o * 2 + 2];
    }
  }

  void pushdown(int o, int c) {
    if(lazy[o]) {
      sum[o * 2 + 1] += c / 2 * lazy[o];
      sum[o * 2 + 2] += (c - c / 2) * lazy[o];
      lazy[o * 2 + 1] = lazy[o];
      lazy[o * 2 + 2] = lazy[o];
      lazy[o] = 0;
    }
  }

  void update(int l, int r, int o, int v) {
    if(l >= opL && r <= opR) {
      sum[o] += (r - l + 1) * v;
      lazy[o] = v;
      return;
    }
    pushdown(o, r - l + 1);
    int m = (l + r) >> 1;
    if(opL <= m) update(l, m, o * 2 + 1, v);
    if(opR > m) update(m + 1, r, o * 2 + 2, v);
    sum[o] = sum[o * 2 + 1] + sum[o * 2 + 2];
  }

  int sumRange(int l, int r, int o) {
    if(l >= opL && r <= opR) return sum[o];
    pushdown(o, r - l + 1);
    int answer = 0;
    int m = (l + r) >> 1;
    if(opL <= m) answer += sumRange(l, m, o * 2 + 1);
    if(opR > m) answer += sumRange(m + 1, r, o * 2 + 2);
    return answer;
  }
public:
  NumArray(vector<int>& nums): _nums(nums){
    len = _nums.size();
    build(0, len - 1);
  }
  
  void update(int index, int val) {
    int diff = val - _nums[index];
    _nums[index] = val;
    opL = index;
    opR = index;
    update(0, len - 1, 0, diff);
  }
  
  int sumRange(int left, int right) {
    opL = left;
    opR = right;
    return sumRange(0, len - 1, 0);
  }
};

// Accepted
// 15/15 cases passed (600 ms)
// Your runtime beats 69.07 % of cpp submissions
// Your memory usage beats 11 % of cpp submissions (165.2 MB)
// @lc code=end


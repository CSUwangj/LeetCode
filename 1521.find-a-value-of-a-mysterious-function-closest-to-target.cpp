/*
 * @lc app=leetcode id=1521 lang=cpp
 *
 * [1521] Find a Value of a Mysterious Function Closest to Target
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
constexpr int maxBit(int x) {
  for(int i = 30; i >= 0 ; --i){
    if((1 << i) & x) return (1 << i);
  }
  return -1;
}
class Solution {
  int len;
  int closestToOneBit(vector<int>& arr, int bit, int target) {
    int pos = 0;
    int result = INT_MAX;
    while(pos < len) {
      if(!(arr[pos] & bit)) {
        pos += 1;
      } else {
        int res = arr[pos];
        while(pos < len && (arr[pos] & bit)) {
          res &= arr[pos];
          pos += 1;
        }
        result = min(result, abs(res - target));
      }
    }
    return result;
  }
public:
  int closestToTarget(vector<int>& arr, int target) {
    int all = (1 << 26) - 1;
    len = arr.size();
    int mmax = 0;
    for(auto n : arr) {
      mmax = max(n, mmax);
      all &= n;
    }
    if(mmax <= target) return target - mmax;
    if(all >= target) return all - target;
    int mBit = (maxBit(target) << 1);
    int bit = mBit;
    int answer = INT_MAX;
    while(bit) {
      answer = min(answer, closestToOneBit(arr, bit, target));
      if(answer != INT_MAX && (mBit >> 2) > bit) return answer;
      bit >>= 1;
    }
    return answer;
  }
};
// @lc code=end


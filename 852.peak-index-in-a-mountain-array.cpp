/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int len = arr.size();
    arr.push_back(-1);
    int low = 0;
    int high = len - 1;
    while(low < high) {
      int mid = (low + high) / 2;
      if(arr[mid] < arr[mid + 1]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
};

// Accepted
// 42/42 cases passed (69 ms)
// Your runtime beats 99.98 % of cpp submissions
// Your memory usage beats 40.39 % of cpp submissions (59.7 MB)
// @lc code=end


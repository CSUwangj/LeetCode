/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int len = arr.size();
    if(k == len) return arr;
    int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    if(pos == 0) return vector<int>(arr.begin(), arr.begin() + k);
    if(pos == len) return vector<int>(arr.end() - k, arr.end());
    int start = pos;
    int sz = (arr[pos] == x);
    while(sz < k) {
      if(start == 0) break;
      if(start + sz == len) {
        start = len - k;
        break;
      }
      if(x - arr[start - 1] <= arr[start + sz] - x) {
        start -= 1;
      }
      sz += 1;
    }
    return vector<int>(arr.begin() + start, arr.begin() + start + k);
  }
};

// Accepted
// 66/66 cases passed (48 ms)
// Your runtime beats 91.78 % of cpp submissions
// Your memory usage beats 78 % of cpp submissions (31.2 MB)
// @lc code=end


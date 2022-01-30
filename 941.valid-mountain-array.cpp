/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
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
  bool validMountainArray(vector<int>& arr) {
    int len = arr.size();
    if(len < 3) return false;
    int pos = 1;
    if(arr[pos] <= arr[pos - 1]) return false;
    while(pos < len && arr[pos] > arr[pos - 1]) pos += 1;
    if(pos == len || arr[pos] == arr[pos - 1]) return false;
    while(pos < len && arr[pos] < arr[pos - 1]) pos += 1;
    return pos == len;
  }
};

// Accepted
// 53/53 cases passed (16 ms)
// Your runtime beats 99.68 % of cpp submissions
// Your memory usage beats 48.39 % of cpp submissions (22.4 MB)
// @lc code=end

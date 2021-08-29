/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
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
  bool isValidSerialization(string preorder) {
    int count = 1;
    int len = preorder.length();
    for (int i = 0; i < len; ++i) {
      if(preorder[i] == '#') {
        count -= 1;
        i += 1;
        if(count == 0 && i != len) return false;
      } else {
        while(i < len && preorder[i] != ',') {
          i += 1;
        }
        count += 1;
      }
    }
    return !count;
  }
};

// Accepted
// 151/151 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 66.91 % of cpp submissions (6.8 MB)
// @lc code=end


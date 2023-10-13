/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
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
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> answer;
    int len1 = nums1.size();
    int len2 = nums2.size();
    if(!len1 || !len2 || !k) return answer;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    for(int i = 0; i < len1; ++i) {
      q.push(make_tuple(nums1[i] + nums2[0], i, 0));
    }
    while(k-- && q.size()) {
      auto [sum, i1, i2] = q.top();
      q.pop();
      answer.push_back(vector<int>{nums1[i1], nums2[i2]});
      if(i2 != len2 - 1) q.push(make_tuple(nums1[i1] + nums2[i2+1], i1, i2+1));
    }
    return answer;
  }
};

// Accepted
// 35/35 cases passed (258 ms)
// Your runtime beats 94.78 % of cpp submissions
// Your memory usage beats 36.56 % of cpp submissions (119.2 MB)
// @lc code=end


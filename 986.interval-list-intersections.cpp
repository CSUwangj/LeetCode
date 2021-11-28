/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
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
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    auto it1 = firstList.begin();
    auto end1 = firstList.end();
    auto it2 = secondList.begin();
    auto end2 = secondList.end();
    vector<vector<int>> answer;
    while(it1 != end1 && it2 != end2) {
      int begin = max((*it1)[0], (*it2)[0]);
      int end = min((*it1)[1], (*it2)[1]);
      if(end >= begin) {
        answer.push_back({begin, end});
      }
      if(end == (*it1)[1]) ++it1;
      if(end == (*it2)[1]) ++it2;
    }
    return answer;
  }
};

// Accepted
// 85/85 cases passed (24 ms)
// Your runtime beats 98.21 % of cpp submissions
// Your memory usage beats 75.13 % of cpp submissions (18.6 MB)
// @lc code=end

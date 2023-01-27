/*
 * @lc app=leetcode id=1962 lang=cpp
 *
 * [1962] Remove Stones to Minimize the Total
 */

// @lc code=start
class Solution {
public:
  int minStoneSum(vector<int>& piles, int k) {
    map<int, int, greater<int>> count;
    int answer = 0;
    for(auto pile : piles) {
      count[pile] += 1;
      answer += pile;
    }
    while(k) {
      auto it = count.begin();
      if(it->first < 2) break;
      if(k > it->second) {
        answer -= (it->first / 2) * it->second;
        count[it->first - it->first / 2] += it->second;
        k -= it->second;
        count.erase(it);
      } else {
        answer -= (it->first / 2) * k;
        k = 0;
      }
    }
    return answer;
  }
};

// Accepted
// 59/59 cases passed (352 ms)
// Your runtime beats 99.48 % of cpp submissions
// Your memory usage beats 5 % of cpp submissions (107.8 MB)
// @lc code=end


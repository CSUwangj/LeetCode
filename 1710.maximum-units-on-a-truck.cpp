/*
 * @lc app=leetcode id=1710 lang=cpp
 *
 * [1710] Maximum Units on a Truck
 */

// @lc code=start
class Solution {
public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[1] > b[1];
    });
    int answer = 0;
    for(auto &boxType : boxTypes) {
      int n = min(truckSize, boxType[0]);
      answer += n * boxType[1];
      truckSize -= n;
      if(!truckSize) break;
    }
    return answer;
  }
};

// Accepted
// 76/76 cases passed (42 ms)
// Your runtime beats 94.62 % of cpp submissions
// Your memory usage beats 53.04 % of cpp submissions (16 MB)
// @lc code=end


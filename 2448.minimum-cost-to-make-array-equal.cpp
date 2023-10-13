/*
 * @lc app=leetcode id=2448 lang=cpp
 *
 * [2448] Minimum Cost to Make Array Equal
 */

// @lc code=start
class Solution {
public:
  long long minCost(vector<int>& nums, vector<int>& cost) {
    int len = nums.size();
    vector<int> indice(len);
    for(int i = 1; i < len; ++i) {
      indice[i] = i;
    }
    sort(indice.begin(), indice.end(), [&](int a, int b) {
      return nums[a] < nums[b];
    });

    long long costs = 0;
    long long addOneCost = cost[indice[0]];
    long long minusOneCost = 0;
    for(int i = len - 1; i > 0; --i) {
      costs += 1LL * (nums[indice[i]] - nums[indice[0]]) * (cost[indice[i]]);
      minusOneCost += cost[indice[i]];
    }
    long long answer = costs;
    for(int i = 1; i < len; ++i) {
      if(nums[indice[i]] == nums[indice[i - 1]]) {
        addOneCost += cost[indice[i]];
        minusOneCost -= cost[indice[i]];
        continue;
      }
      int diff = nums[indice[i]] - nums[indice[i - 1]];
      costs += 1LL * diff * addOneCost;
      costs -= 1LL * diff * minusOneCost;
      addOneCost += cost[indice[i]];
      minusOneCost -= cost[indice[i]];
      answer = min(costs, answer);
    }

    return answer;
  }
};

// Accepted
// 48/48 cases passed (130 ms)
// Your runtime beats 29.93 % of cpp submissions
// Your memory usage beats 51.46 % of cpp submissions (39.4 MB)
// @lc code=end


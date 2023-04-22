/*
 * @lc app=leetcode id=2300 lang=cpp
 *
 * [2300] Successful Pairs of Spells and Potions
 */

// @lc code=start
class Solution {
public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    int prefix[100001] = {};
    for(auto potion : potions) {
      if((success + (potion - 1)) / potion > 100000) continue;
      prefix[(success + (potion - 1)) / potion] += 1;
    }
    for(int i = 1; i <= 100000; ++i) {
      prefix[i] += prefix[i - 1];
    }
    vector<int> answer;
    answer.reserve(spells.size());
    for(auto spell : spells) {
      answer.push_back(prefix[spell]);
    }
    return answer;
  }
};

// Accepted
// 56/56 cases passed (197 ms)
// Your runtime beats 99.56 % of cpp submissions
// Your memory usage beats 67.55 % of cpp submissions (97.6 MB)
// @lc code=end


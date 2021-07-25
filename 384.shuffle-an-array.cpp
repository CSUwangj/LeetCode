/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 */

// @lc code=start
using random_param = uniform_int_distribution<int>::param_type;
class Solution {
  vector<int> arr;
  int len;
  random_device rd;
  mt19937 gen{rd()};
  uniform_int_distribution<int> distr;
public:
  Solution(vector<int>& nums): arr(nums) {
    len = nums.size();
  }
  
  /** Resets the array to its original configuration and return it. */
  vector<int> reset() {
    return arr;
  }
  
  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    vector<int> result = arr;
    for(int i = len - 1; i ; --i) {
      distr.param(random_param(0, i));
      int idx = distr(gen);
      swap(result[idx], result[i]);
    }
    return result;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end


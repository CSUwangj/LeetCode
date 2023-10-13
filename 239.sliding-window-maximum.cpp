/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> monoQueue;
    for(int i = 0; i < k; ++i) {
      while(monoQueue.size() && monoQueue.back() < nums[i]) monoQueue.pop_back();
      monoQueue.push_back(nums[i]);
    }
    vector<int> answer{monoQueue.front()};
    for(int i = k; i < nums.size(); ++i) {
      while(monoQueue.size() && monoQueue.back() < nums[i]) monoQueue.pop_back();
      if(monoQueue.size() && monoQueue.front() == nums[i-k]) monoQueue.pop_front();
      monoQueue.push_back(nums[i]);
      answer.push_back(monoQueue.front());
    }
    return answer;
  }
};

// Accepted
// 51/51 cases passed (199 ms)
// Your runtime beats 91.73 % of cpp submissions
// Your memory usage beats 45.65 % of cpp submissions (134.7 MB)
// @lc code=end


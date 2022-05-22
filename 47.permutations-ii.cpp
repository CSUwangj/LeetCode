/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
  bool next_permutation(vector<int>& nums) {
    if(nums.size() < 2) return false;
    int len = nums.size();
    int a = len - 2;
    
    while(a >= 0 && nums[a] >= nums[a+1]) a -= 1;
    if(a == -1) return false;
    
    int minGreater = INT_MAX, b = -1;
    int i = a+1;
    while(i < len) {
      if(nums[i] > nums[a] && nums[i] < minGreater) {
        b = i;
        minGreater = nums[i];
      }
      i += 1;
    }
    
    swap(nums[a], nums[b]);
    sort(nums.begin()+a+1, nums.end());
    return true;
  }
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans{nums};
    while(next_permutation(nums)) {
        ans.push_back(nums);
    }
    return ans;
  }
};

// Accepted
// 33/33 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 89.32 % of cpp submissions (8.5 MB)
// @lc code=end

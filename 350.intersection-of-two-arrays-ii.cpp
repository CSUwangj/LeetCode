/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> answer;
    auto it1 = nums1.begin();
    auto it2 = nums2.begin();
    while(it1 != nums1.end() && it2 != nums2.end()) {
      if(*it1 == *it2) {
        answer.push_back(*it1);
        ++it1;
        ++it2;
      } else if(*it1 < *it2) {
        ++it1;
      } else {
        ++it2;
      }
    }

    return answer;
  }
};

// Accepted
// 55/55 cases passed (3 ms)
// Your runtime beats 91.05 % of cpp submissions
// Your memory usage beats 88.6 % of cpp submissions (9.9 MB)
// @lc code=end


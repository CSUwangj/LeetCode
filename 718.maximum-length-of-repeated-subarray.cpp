/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
class Solution {
public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    int answer = 0;
    for(int i = 0; i < len1; i++) {
      if(answer > len1 - i) break;
      for(int j = 0; j < len2; j++) {
        if(answer > len2 - j) break;
        int k = 0;;
        while(i + k < len1 && j + k < len2 && nums1[i + k] == nums2[j + k]){
          k += 1;
        }
        answer = max(k, answer);
      }
    }
    return answer;
  }
};
// @lc code=end


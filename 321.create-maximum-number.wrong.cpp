/*
 * @lc app=leetcode id=321 lang=cpp
 *
 * [321] Create Maximum Number
 */

// @lc code=start
bool cmp(const vector<int> &v1, int i1, const vector<int> &v2, int i2) {
  while(i1 < v1.size() && i2 < v2.size()) {
    if(v1[i1] != v2[i2]) return v1[i1] < v2[i2];
    i1 += 1;
    i2 += 1;
  }
  return i1 < v1.size();
}
class Solution {
  int getCur(const vector<int> &v1, int &i1, const vector<int> &v2, int &i2) {
    if(cmp(v1, i1, v2, i2)) {
      return v2[i2++];
    }
    return v1[i1++];
  }
public:
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> answer;
    int pos1 = 0;
    int pos2 = 0;
    int len1 = nums1.size();
    int len2 = nums2.size();
    while(pos1 < len1 && pos2 < len2) {
      int cur = getCur(nums1, pos1, nums2, pos2);
      while(answer.size() && answer.back() < cur && len1 - pos1 + len2 - pos2 + answer.size() >= k) {
        answer.pop_back();
      }
      answer.push_back(cur);
    }
    vector<int> &rest = pos1 == len1 ? nums2 : nums1;
    int restIndex = pos1 == len1 ? pos2 : pos1;
    int restLen = rest.size();
    while(restIndex < restLen) {
      int cur = rest[restIndex++];
      while(answer.size() && answer.back() < cur && restLen - restIndex + answer.size() >= k) {
        answer.pop_back();
      }
      answer.push_back(cur);
    }
    return answer;
  }
};
// @lc code=end


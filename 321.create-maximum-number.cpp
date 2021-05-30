/*
 * @lc app=leetcode id=321 lang=cpp
 *
 * [321] Create Maximum Number
 */

// @lc code=start
string getNumber(vector<int> &nums, int remove) {
  string answer;
  for(auto i : nums) {
    while(answer.length() && answer.back() < i && remove) {
      answer.pop_back();
      remove -= 1;
    }
    answer.push_back(char(i));
  }
  while(remove--) answer.pop_back();
  return answer;
}

bool lexicGreater(string &s1, int pos1, string &s2, int pos2) {
  for(int i = 0; i + pos1 < s1.length() && i + pos2 < s2.length(); ++i) {
    if(s1[i + pos1] != s2[i + pos2]) return s1[i + pos1] > s2[i + pos2];
  }
  return s1.length() - pos1 > s2.length() - pos2;
}

string merge(string &s1, string &s2) {
  int pos1 = 0;
  int pos2 = 0;
  int len1 = s1.length();
  int len2 = s2.length();
  string answer;
  while(pos1 < len1 && pos2 < len2) {
    if(lexicGreater(s1, pos1, s2, pos2)) {
      answer.push_back(s1[pos1++]);
    } else {
      answer.push_back(s2[pos2++]);
    }
  }
  while(pos1 < len1) answer.push_back(s1[pos1++]);
  while(pos2 < len2) answer.push_back(s2[pos2++]);
  return answer;
}
class Solution {
public:
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    int diff = len1 + len2 - k;
    string answer;
    for(int i = 0; i <= diff; ++i) {
      int j = diff - i;
      if(i > len1 || j > len2) continue;
      string s1 = getNumber(nums1, i);
      string s2 = getNumber(nums2, j);
      answer = max(answer, merge(s1, s2));
    }
    vector<int> realAnswer;
    for(auto c : answer) realAnswer.push_back(c);
    return realAnswer;
  }
};
// @lc code=end


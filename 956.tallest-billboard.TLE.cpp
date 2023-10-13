/*
 * @lc app=leetcode id=956 lang=cpp
 *
 * [956] Tallest Billboard
 */

// @lc code=start
template<typename T>
std::ostream& operator<<(std::ostream &out, const std::vector<T> &v) {
  if(v.size() == 0) {
    out << "[]" << std::endl;
    return out;
  }
  out << '[' << v[0];
  for(int i = 1; i < v.size(); ++i) {
    out << ", " << v[i];
  }
  out << ']';
  return out;
}
class Solution {
public:
  int tallestBillboard(vector<int>& rods) {
    map<int, vector<int>, greater<int>> combinations;
    int len = rods.size();
    for(int i = 1; i < (1 << len); ++i) {
      int h = 0;
      for(int m = 0; m < len; ++m) {
        if((1 << m) & i) h += rods[m];
      }
      combinations[h].push_back(i);
    }
    for(const auto &[height, combinations] : combinations) {
      if(combinations.size() < 2) continue;
      for(int i = 0; i < combinations.size(); ++i) {
        for(int j = i + 1; j < combinations.size(); ++j) {
          if(!(combinations[i] & combinations[j])) return height;
        }
      }
    }
    return 0;
  }
};
// @lc code=end


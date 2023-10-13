/*
 * @lc app=leetcode id=2336 lang=cpp
 *
 * [2336] Smallest Number in Infinite Set
 */

// @lc code=start
class SmallestInfiniteSet {
  set<int> back;
  int smallest;
public:
  SmallestInfiniteSet() {
    smallest = 1;
  }
  
  int popSmallest() {
    int result;
    if(back.size()) {
      result = *back.begin();
      back.erase(back.begin());
    } else {
      result = smallest;
      smallest += 1;
    }
    return result;
  }
  
  void addBack(int num) {
    if(num < smallest) {
      back.insert(num);
    }
  }
};

// Accepted
// 135/135 cases passed (92 ms)
// Your runtime beats 67.35 % of cpp submissions
// Your memory usage beats 84.48 % of cpp submissions (35.5 MB)
// @lc code=end


/*
 * @lc app=leetcode id=284 lang=cpp
 *
 * [284] Peeking Iterator
 */

// @lc code=start
class PeekingIterator : public Iterator {
  int num;
  bool has;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
      has = Iterator::hasNext();
      if(has) num = Iterator::next();
    }
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
      return num;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
    int cur = num;
    has = Iterator::hasNext();
    if(has) num = Iterator::next();
    return cur;
	}
	
  bool hasNext() const {
    return has;
  }
};

// Accepted
// 14/14 cases passed (4 ms)
// Your runtime beats 59.03 % of cpp submissions
// Your memory usage beats 72 % of cpp submissions (7.5 MB)
// @lc code=end


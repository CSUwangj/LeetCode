/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 */

// @lc code=start
const set<string> st = {"011237","0122579","012356789","0124","0134449","0145678","01466788","0248","0368888","0469","1","112234778","11266777","122446","125","128","1289","13468","16","2","224588","23","23334455","234455668","23678","256","35566","4","46","8"};
class Solution {
public:
  bool reorderedPowerOf2(int N) {
    string n = to_string(N);
    sort(n.begin(), n.end());
    return st.count(n);
  }
};

// Accepted
// 136/136 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 83.9 % of cpp submissions (6 MB)
// @lc code=end


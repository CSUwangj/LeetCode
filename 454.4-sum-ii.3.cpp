/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
// copied from solution
const int N = 360007;
class Hash{
  int keys[N]={0};
  int values[N]={0};
public:
    Hash(){
      memset(values, 0, sizeof(values));
    }
    int& operator [](int n){
      int idx = (n%N + N)%N, cnt=1;
      while(keys[idx]!=n && values[idx]!=0){
        idx = (idx+cnt*cnt)%N;
        cnt += 1;
      }
      keys[idx] = n;
      return values[idx];
    }
};
class Solution {
public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    Hash m;
    for(auto j:nums3) {
      for(auto i: nums4){
        m[i+j]++;
      }
    }

    int count=0;
    for(auto a:nums1) {
      for(auto b:nums2){
        count+=m[-(a+b)];
      }
    }
    return count;
  }
};

// Accepted
// 132/132 cases passed (91 ms)
// Your runtime beats 99.96 % of cpp submissions
// Your memory usage beats 49.44 % of cpp submissions (24.5 MB)
// @lc code=end

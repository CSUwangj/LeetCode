#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
using namespace std;

class NumArray {
  vector<int> original;
  vector<int> bit;
  int lowbit(int x) {
    return x&(-x);
  }
  int sum(int x) {
    int ans = 0;
    while(x) {
      ans += bit[x];
      x -= lowbit(x);
    }
    return ans;
  }
  void add(int pos, int val) {
    while(pos < bit.size()) {
      bit[pos] += val;
      pos += lowbit(pos);
    }
  }
public:
  NumArray(vector<int>& nums) {
    original = nums;
    bit = vector<int>(nums.size()+1, 0);
    for (int i = 0; i < nums.size(); ++i) {
      add(i+1, nums[i]);
    }
  }
  
  void update(int i, int val) {
    int diff = val - original[i];
    original[i] = val;
    add(i+1, diff);
    return;
  }
  
  int sumRange(int i, int j) {
    return sum(j+1) - sum(i);
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

int main() {
  vector<int> data = {1, 3, 5};
  auto sol = NumArray(data);
  cout << sol.sumRange(0, 2) << endl;
  sol.update(1, 2);
  cout << sol.sumRange(0, 2) << endl;
  data = {-1};
  sol = NumArray(data);
  cout << sol.sumRange(0, 0) << endl;
  return 0;
}
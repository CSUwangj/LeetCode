#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class NumArray {
  vector<int> val;
  vector<int> lazy;
  int operation_begin;
  int operation_end;
  int size;
  void build(vector<int>& nums, int root_index, int begin, int end) {
    if(begin == end) {
      val[root_index] = nums[begin];
    } else {
      int mid = (begin + end) >> 1;
      build(nums, root_index*2+1, begin, mid);
      build(nums, root_index*2+2, mid+1, end);
      val[root_index] = val[root_index*2+1] + val[root_index*2+2];
    }
  }
  void pushdown(int root_index, int count) {
    if(lazy[root_index]) {
      val[root_index*2+1] += (count - count/2)*lazy[root_index];
      val[root_index*2+2] += (count/2)*lazy[root_index];
      lazy[root_index*2+1] += lazy[root_index];
      lazy[root_index*2+2] += lazy[root_index];
      lazy[root_index] = 0;
    }
  }
  void update(int root_index, int begin, int end, int difference) {
    if(operation_begin <= begin && operation_end >= end) {
      val[root_index] += difference * (operation_end-operation_begin+1);
      lazy[root_index] += difference;
      return;
    }
    pushdown(root_index, end-begin+1);
    int mid = (end + begin) >> 1;
    if(operation_begin <= mid) update(root_index*2+1, begin, mid, difference);
    if(operation_end > mid) update(root_index*2+2, mid+1, end, difference);
    val[root_index] = val[root_index*2+1] + val[root_index*2+2];
  }
  int query(int root_index, int begin, int end) {
    if(operation_begin <= begin && operation_end >= end) {
      return val[root_index];
    }
    pushdown(root_index, end-begin+1);
    int ans = 0;
    int mid = (begin + end) >> 1;
    if(operation_begin <= mid) ans += query(root_index*2+1, begin, mid);
    if(operation_end > mid) ans += query(root_index*2+2, mid+1, end);
    return ans;
  }
public:
  NumArray(vector<int>& nums) {
    val = vector<int>(nums.size()*4);
    lazy = vector<int>(nums.size()*4);
    size = nums.size()-1;
    if(size == 0) return;
    build(nums, 0, 0, size);
  }
  
  void update(int i, int val) {
    operation_begin = i;
    operation_end = i;
    int diff = val - query(0, 0, size);
    update(0, 0, size, diff);
  }
  
  int sumRange(int i, int j) {
    operation_begin = i;
    operation_end = j;
    return query(0, 0, size);
  }
};


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
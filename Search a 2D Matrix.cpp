#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(!matrix.size() || !matrix[0].size()) return false;
    int begin = 0, end = matrix[0].size()*matrix.size()-1, l=matrix[0].size();
    while(begin < end) {
      int mid = (begin + end)/2;
      if(matrix[mid/l][mid%l] >= target) {
        end = mid;
      } else {
        begin = mid+1;
      }
    }
    return matrix[end/l][end%l]==target;
  }
};

int main() {
  vector<pair<vector<vector<int>>, int>> data = {
    {{{1,3,5,7},{10,11,16,20},{23,30,34,50}}, 13},
    {{{1,3,5,7},{10,11,16,20},{23,30,34,50}},  3},
    {{{1,3,5,7},{10,11,16,20},{23,30,34,50}},  1},
    {{{1,3,5,7},{10,11,16,20},{23,30,34,50}}, 50},
    {{}, 10},
    {{{}}, 10},
    {{{1}}, 2}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.searchMatrix(data.first, data.second);
    cout << ans << endl;
  } 
  return 0;
}
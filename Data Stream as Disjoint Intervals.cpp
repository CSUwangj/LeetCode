#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class SummaryRanges {
  vector<vector<int>> intervals = {{-2, -2}};
public:
  void addNum(int val) {
    auto end = intervals.end(), begin = intervals.begin();
    while(begin < end) {
      auto mid = begin;
      advance(mid, distance(begin, end)/2);
      if((*mid)[0] <= val && (*mid)[1] >= val) {
        return;
      } else if((*mid)[0] > val) {
        end = mid;
      } else if((*mid)[1] < val) {
        begin = mid + 1;
      }
    }
    if(begin != intervals.end() && ((*(begin))[0] == val+1) && ((*(begin-1))[1] == val-1)) {
      (*(begin-1))[1] = (*(begin))[1];
      intervals.erase(begin);
    } else if(begin != intervals.end() && (*(begin))[0] == val+1) {
      (*(begin))[0] = val;
    } else if((*(begin-1))[1] == val-1){
      (*(begin-1))[1] = val;
    } else {
      intervals.insert(begin, {val, val});
    }
  }
  
  vector<vector<int>> getIntervals() {
    return vector<vector<int>> {intervals.begin()+1, intervals.end()};
  }
};

void printResult(vector<vector<int>>& intervals){
  cout << '[';
  for(unsigned int i = 0; i < intervals.size();++i) {
    cout << '[' << intervals[i][0] << ", " << intervals[i][1] << ']' << ",]"[i==intervals.size()-1];
  }
  cout << endl;
}

int main() {
  auto sol = SummaryRanges();
  sol.addNum(1);
  auto res = sol.getIntervals();
  printResult(res);
  // sol.addNum(3);
  sol.addNum(0);
  res = sol.getIntervals();
  printResult(res);
  sol.addNum(7);
  res = sol.getIntervals();
  printResult(res);
  sol.addNum(2);
  res = sol.getIntervals();
  printResult(res);
  sol.addNum(6);
  res = sol.getIntervals();
  printResult(res);
  return 0;
}
// Copyright 2020 <CSUwangj@protonmail.com>
#include<bits/stdc++.h>
#define LL int64
#define mk(a, b) make_pair(a, b)
#define ULL uint64
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
  long long makePalindrom(long long n, bool odd) {
    long long tmp = n;
    if(odd) tmp /= 10;
    while(tmp) {
      n *= 10;
      n += tmp % 10;
      tmp /= 10;
    }
    return n;
  }
public:
  string nearestPalindromic(string n) {
    if(n == "10" || n == "11") return "9";
    int len = n.length();
    long long n_half = stoll(string(n.begin(), n.begin()+(len+1)/2));
    bool odd_length = len&1;
    long long middle = makePalindrom(n_half, odd_length);
    long long n_num = stoll(n);
    long long min_difference = LONG_LONG_MAX;
    vector<long long> candidates;
    long long less_num = makePalindrom(n_half-1, odd_length);
    if(less_num && LONG_LONG_MAX/10 > less_num && less_num * 10 < n_num) less_num = less_num*10+9;
    candidates.push_back(less_num);
    min_difference = min(min_difference, n_num-less_num);
    if(middle != n_num) {
      candidates.push_back(middle);
      min_difference = min(min_difference, abs(middle - n_num));
    }
    long long more_num = makePalindrom(n_half+1, odd_length);
    if(LONG_LONG_MAX/10 > n_num && n_num * 10 < more_num) more_num = more_num/10+1;
    candidates.push_back(more_num);
    min_difference = min(min_difference, more_num-n_num);
    for(auto candidate : candidates) {
      if(abs(candidate - n_num) == min_difference) return to_string(candidate);
    }
    return "WTF";
  }
};

int main() {
  vector<string> data = {
    // "10",
    // "11",
    // "12",
    // "9",
    // "0",
    // "1",
    // "2",
    // "99",
    // "123",
    // "999",
    // "1234",
    // "100002",
    // "100001",
    // "1000001",
    // "999999999999999999",
    "123898321"
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.nearestPalindromic(data);
    cout << ans << endl;
  } 
  return 0;
}
// Copyright 2020 <CSUwangj@protonmail.com>
#include<bits/stdc++.h>
#define LL int64
#define mk(a, b) make_pair(a, b)
#define ULL uint64
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
  string parseAtom(string &formula, int &position) {
    string atom = "";
    atom += formula[position];
    position += 1;
    while(position < formula.size() && islower(formula[position])) {
      atom += formula[position];
      position += 1;
    }
    return atom;
  }
  
  map<string, int> parseFormula(string &formula, int &position) {
    map<string, int> currentCount;
    while(position < formula.size() && formula[position] != ')') {
      if(isupper(formula[position])) {
        string atom = parseAtom(formula, position);
        int count = parseCount(formula, position);
        currentCount[atom] += count;
      } else if(formula[position] == '(') {
        position += 1;
        map<string, int> subCount = parseFormula(formula, position);
        int count = parseCount(formula, position);
        for(auto &[atom, acount] : subCount) {
          currentCount[atom] += acount * count;
        }
      }
    }
    if(position < formula.size()) position += 1;
    return currentCount;
  }
  
  int parseCount(string &formula, int &position) {
    if(position >= formula.size() || !isdigit(formula[position])) return 1;
    int count = 0;
    while(position < formula.size() && isdigit(formula[position])) {
      count *= 10;
      count += formula[position] - '0';
      position += 1;
    }
    return count;
  }
public:
  string countOfAtoms(string formula) {
    int position = 0;
    map<string, int> count = parseFormula(formula, position);

    string answer = "";
    for(auto &[atom, acount] : count) {
      answer += atom;
      if(acount != 1) answer += to_string(acount);
    }

    return answer;
  }
};

int main() {
  vector<string> data = {
    "Mg(OH)2",
    "K4(ON(SO3)2)2",
    "H20",
    "(HOH)"
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.countOfAtoms(data);
    cout << ans << endl;
  } 
  return 0;
}